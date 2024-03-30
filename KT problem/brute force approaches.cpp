#include <iostream>
#include <array>
#include <iomanip>
#include <ctime>

const size_t arraySize = 4;
const size_t santracSize = 8;

void knightsTour(std::array<std::array<int, santracSize>, santracSize> &santranc, int currentRow, int currentCol);
int main(void){

	std::array<std::array<int, santracSize>, santracSize> santranc ={};
	int currentRow = 0;
	int currentCol = 0;
	std::cout<< "Lufen baslangic noktasi secin 8x8\n";
	std::cin>>currentRow>>currentCol;
	knightsTour(santranc, currentRow, currentCol);
	for(unsigned int i = 0; i < santranc.size(); ++i){
		for(unsigned int j = 0; j < santranc[i].size(); ++j){
			std::cout<<std::right<<std::setw(5)<<santranc[i][j];
		}
		std::cout<<std::endl;
	}
	return 0;
	
}
void knightsTour(std::array<std::array<int, santracSize>, santracSize> &santranc, int currentRow, int currentCol){
	

	std::srand(static_cast<unsigned int>(time(0)));
	std::array<int, arraySize> vertical = {-2, 2, -1, 1};
	std::array<int, arraySize>  horizontal = {-1, 1, -2, 2};
	
	int ran1 = 0;
	int ran2 = 0;
	
	int moveNumber = 1;
	santranc[currentRow][currentCol] = moveNumber;
	int startPointRow = currentRow;
	int startPointCol = currentCol;

	for(unsigned i = 0; i < 64000; ++i){
		
		ran1 = rand() % 4;
		ran2 = rand() % 4;
		if(vertical[ran1] != horizontal[ran2] && vertical[ran1] != - horizontal[ran2]){

			currentRow = startPointRow + vertical[ran1];
			currentCol = startPointCol + horizontal[ran2];
		
		    if(santranc[currentRow][currentCol] != 0 || currentRow >= 8 || currentCol >= 8 || currentRow < 0 || currentCol < 0 ){
			    continue;
			}else{
			    santranc[currentRow ][currentCol] = ++moveNumber;
		    }
		}	
	}
}