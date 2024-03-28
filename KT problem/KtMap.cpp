#include <iostream>
#include <iomanip>
#include <array>
#include <ctime>
#include <random>

const int row = 8;
const int col = 8;

void chesMap(std::array<std::array<int, row>, col> santranc, int startPointRow, int startPointCol, const std::array<int, row> &dikey, const std::array<int, col> &yatay);
void short_Path(std::array<std::array<int, row>, col> &santranc, int startPointRow, int startPointCol, const std::array<int, row> &dikey, const std::array<int, col> &yatay);
int main(void){
    
    std::array<int, row> dikey = {-1, -2, -2, -1,  1,  2, 2, 1}; // satır ile ilerleme
    std::array<int, col> yatay = { 2,  1, -1, -2, -2, -1, 1, 2}; // sutun ile ilerleme
    std::array<std::array<int, row>, col> santranc {};

    for(size_t rows = 0; rows < 8; ++rows){
        for(size_t cols = 0; cols < 8; ++cols){
            chesMap(santranc, rows, cols, dikey, yatay);
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    
    //baslangic noktaları
    int startPointRow = 6; 
    int startPointCol = 5;

    short_Path(santranc, startPointRow, startPointCol, dikey, yatay);
    
    
    return 0;
}

void short_Path(std::array<std::array<int, row>, col> &santranc, int startPointRow, int startPointCol, const std::array<int, row> &dikey, const std::array<int, col> &yatay){

    
    
    //baslangic noktaları gidilecek yola aktar
    int currentRow = startPointRow; 
    int currentCol = startPointCol;
    
    //en dar gidilecek yolu bulmak için saklanacak yol
    int shortPath = 100;

    for(int i = 0; i < 8; ++i){
        
        currentRow = startPointRow + dikey[i]; // baslangic noktasindan baslar (satır)
        currentCol = startPointCol + yatay[i]; // baslangic noktasindan baslar (sütün)

        if(currentRow < 0) // dizi indisleri eksi(-) olmaz bu yüzden pozitife çeviriyoruz
            currentRow *= -1;
        if(currentCol < 0)
            currentCol *= -1;
        
        if(santranc[currentRow][currentCol] < shortPath)
            shortPath = santranc[currentRow][currentCol];
    }
    std::cout<<"En kisa yol bulundu"<<std::endl;
    std::cout<<currentRow<<". satir ve " <<currentCol<< ". sutun"; 
}

void chesMap(std::array<std::array<int, row>, col> santranc, int startPointRow, int startPointCol, const std::array<int, row> &dikey, const std::array<int, col> &yatay){

    int moveNumber = 1;

    for(int i = 0; i < 8; ++i){

        if(startPointRow + dikey[i] < 0 || startPointRow + dikey[i] >= row || startPointCol + yatay[i] < 0 || startPointCol + yatay[i] >= col)
            continue;
        else
            santranc[startPointRow][startPointCol] += moveNumber;     
    }
    std::cout<<std::right<<std::setw(4)<<santranc[startPointRow][startPointCol];            

}