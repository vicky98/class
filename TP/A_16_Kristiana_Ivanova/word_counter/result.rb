# ruby -IA_16_Kristiana_Ivanova/ A_16_Kristiana_Ivanova.rb + programa.rb

module WordCounter
	require 'json'
	require 'rexml/document'
	require 'stringio'
	require 'sqlite3'

class Result
	
  	attr_accessor :marks_count
  	attr_accessor :word_counts

  	def initialize
    		@marks_count = 0
    		@word_counts = Hash.new(0)
  	end
  	
  	def merge_results(res2)
  		word_counts.merge!(res2.word_counts.to_h) { |_, oldval, newval| newval + oldval }
  		word_counts = word_counts.sort_by { |item, amount| [-amount, item] }.to_h
  		marks_count += res2.marks_count
	end
  # -------------------------------------------------------------------------
	def save_to_database
		db = SQLite3::Database.new 'A_16_Kristiana_Ivanova.db'
		db.results_as_hash = true
		 
		db.execute <<-SQL
			CREATE TABLE IF NOT EXISTS statistics (
				id int,
				source_name string,
				hash string
			);
			SQL
			db.execute <<-SQL
				CREATE TABLE IF NOT EXISTS word_counts (
					statistics_id int,
					word string,
					count int
				);
			SQL
			
		tempt = WordCounter::Result.new({},0)
		db.execute "SELECT word, count FROM word_counts" do |row|
			db.execute "DELETE FROM word_counts WHERE word=?", row["word"]
			if row["word"] == '$marks$'
				tempt.marks_count = row["count"]
			else
				tempt.word_counts[row["word"].to_s] = row["count"]
			end
		end
	
		merge_results(tempt) if tempt.word_counts.size > 0
				
		word_counts.each do |item, amount|
			db.execute "INSERT INTO word_counts VALUES(?, ?, ?);", nil, item, amount
		end		
			
		db.execute "INSERT INTO word_counts VALUES(?, ?, ?);", nil, 'marks', marks_count
	end			
  # --------------------------------------------------------
	def to_csv
		word_counts.each do |item, amount|
			puts item + "," + amount.to_s
		end

		if marks_count != 0
			puts "\"marks\"," + marks_count.to_s
		end
	end

  # -----------------------------------------------------
  
	def to_xml
		xml_document = REXML::Document.new
		xml_item_counts = xml_document.add_element 'word-counts'
		xml_marks = xml_item_counts.add_element 'marks'
		xml_marks.add_text "#{marks_count}"
		xmls_items = xml_item_counts.add_element 'words' # xml words

		word_counts.each do |item, amount|
			item = xmls_items.add_element('word', 'count' => amount).text = "#{item}" #item = word
		end

		formatter = REXML::Formatters::Pretty.new(2)
		formatter.compact = true
		formatter.write(xml_document, $stdout)
	end

  # ----------------------------------------------------

	def to_json
		json_output = { "marks" => marks_count, "items" => word_counts}
		puts JSON.pretty_generate(json_output)
	end

	def rect x,y,width,height
		'<rect width="'+width.to_s+'" y ="'+y.to_s+'" x ="'+x.to_s+'" height="'+height.to_s+'" style="fill:rgb(0,0,0);stroke-width:3;stroke:rgb(0,0,0)"/>'
	end
		
	def to_svg
		File.open("result.svg","w") do |f|
			f.write('<svg xmlns="http://www.w3.org/2000/svg">')
			temp = word_counts.first.last
			y = temp
			temp = temp/200 +1 
			x = 40
			
			word_counts.each do |item, amount|
				temp_y = (300- y)-y
				f.write(rect(x,temp_y,30,temp*amount*10))
				f.write('<text x="'+(x+2).to_s+'" y="'+(temp_y-7).to_s+'" textLength = "'+(item.length*5).to_s+'" fill="black">'+item+'</text>')
				x+=60
			end
	
			f.write('</svg>')
		end
	end
end
