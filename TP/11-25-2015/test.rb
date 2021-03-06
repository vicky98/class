require 'word_counter'
describe WordCounter::Parser do 
	describe '#parse' do 
		it 'counts marks correctly' do 
			parser = Wordcounter::Parser.new
		
			result = parser.parse('This is my test!')
		
			expect(result.marks_count).to eq(2)
		end
		it 'counts words correctly' do 
			parser = Wordcounter::Parser.new
		
			result = parser.parse('This is my test! My ohh my')
		
			expect(result.marks_counts['my']).to eq(3)
			expect(result.marks_counts['test']).to eq(1)
			expect(result.marks_counts['this']).to eq(1)
			expect(result.marks_counts['this']).not_to eq(10)
		end
	end
end
