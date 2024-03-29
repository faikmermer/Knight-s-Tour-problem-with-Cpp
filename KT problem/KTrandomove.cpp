#include <iostream>
#include <array>
#include <ctime>
#include <iomanip>

int main(void){

	const size_t arraySize = 4;
	const size_t santracSize = 8;

	std::srand(static_cast<unsigned int>(time(0)));
	std::array<int, arraySize> vertical = {-2, 2, -1, 1};
	std::array<int, arraySize>  horizontal = {-1, 1, -2, 2};
	std::array<std::array<int, santracSize>, santracSize> santranc ={};
	
	int ran1 = 0;
	int ran2 = 0;
	int currentRow = 3;
	int currentCol = 4;
	int moveNumber = 1;
	int moveCount = 0;
	int prevRow = currentRow;
	int prevCol = currentCol;
	santranc[currentRow][currentCol] = moveNumber;

	for(unsigned i = 0; i < 1000; ++i){
		

		ran1 = rand() % 4;
		ran2 = rand() % 4;
		if(vertical[ran1] != horizontal[ran2] && vertical[ran1] != - horizontal[ran2]){
			currentRow += vertical[ran1];
			currentCol += horizontal[ran2];

			if(currentRow < 0)
				currentRow *= -1;
			if(currentCol < 0)
				currentCol *= -1;

			if(santranc[currentRow][currentCol] != 0 || currentRow == prevRow || currentCol == prevCol || currentCol >= 8 || currentRow >= 8){
				++moveCount;
			    currentRow = prevRow;
			    currentCol = prevCol;
			    if(moveCount == 15)
			    	break;

			    continue;
			}else{
				santranc[currentRow][currentCol] = ++moveNumber;
				prevRow = currentRow;
	            prevCol = currentCol;
				moveCount = 0;
			}
		}	
	}

	for(auto const &row:santranc){
		for(auto const &col:row){
			std::cout<<std::right<<std::setw(5)<<col<<" ";
		}
		std::cout<<std::endl;
	}
		
}