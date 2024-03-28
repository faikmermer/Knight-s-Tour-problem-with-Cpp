
#include <iostream>
#include <array>
#include <iomanip>

using namespace std;
const size_t row = 8;
const size_t col = 8;
void knightsTour(array<array<int, col>, row> santranc, int startPointRow, int startPointCol);

int main(void){

    int startPointRow = 0;
    int startPointCol = 0;
    array<array<int, col>, row> santranc = {};

    knightsTour(santranc, startPointRow, startPointCol);

    
    return 0;
}


void knightsTour(array<array<int, col>, row> santranc, int startPointRow, int startPointCol){
    array<int, row> dikey = {-1, -2, -2, -1,  1,  2, 2, 1}; // satır ile ilerleme
    array<int, col> yatay = { 2,  1, -1, -2, -2, -1, 1, 2}; // sutun ile ilerleme

    int currentRow = startPointRow; //başlangıç noktası dikey alan
    int currentCol = startPointCol; // başlangıç noktası yatay alan
     
    //Önceki konum bilgileri sakla
    int prevRow = 0;
    int prevCol = 0;

    int moveNumber = 1; //hareket edilme numarası
    int moveCount = 0;  //Her alan dolu olması kontrolünü sağlayacak değikenimiz

    santranc[currentRow][currentCol] = 1; // başlangıç noktamız


    for(unsigned i = 0; i <= 256; ++i){


        prevRow = currentRow;
        prevCol = currentCol;
        if((i + 1) % 9 == 0)
            i = 0;
        
        currentRow += dikey[i];
        currentCol += yatay[i];
        
        //dizimizde 0'dan düşük deger olmayacak şekilde ayarlıyoruz
        if(currentRow < 0 )
          currentRow *= -1;
        if(currentCol < 0)
          currentCol *= -1;

        // Konumlarımız kontrol etme şartları
        if(santranc[currentRow][currentCol] != 0  || currentCol == prevCol || currentRow == prevRow || currentRow >= 8 || currentCol >= 8){
            ++moveCount;
            currentRow = prevRow;
            currentCol = prevCol;            

            if(moveCount == 8){ // Bütün durumlar kontrol edildiğinde bitiriyoruz programı
                cout<<"Gidilecek yol yok!" <<setw(5)<<moveNumber<<". adimda kaldi!"<<endl;
                break;
            }
            continue;
            //santranc[startPointRow][startPointCol] = moveNumber + 1; Kaç tane yol ile gidilebilir sayısını verir
        }else{
            santranc[currentRow][currentCol]  = ++moveNumber;
            moveCount = 0;
        }
    }

    //dizi yazdirma
    for(size_t i = 0; i < santranc.size(); ++i){
        for(size_t j = 0; j < santranc[i].size();++j){

            cout<<right<<setw(4)<<santranc[i][j];
        }
        cout<<endl;
    }
}