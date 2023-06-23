namespace ligongbinde {
       //-------------------------------------------
       //一组这样的Int型变量 存一个大量。
       using Int = unsigned long long  int;
       //-------------------------------------------
       //一个Int型变量存这么多个量字
       int const TOTAL = ( 4 + 5 );   
       //-------------------------------------------
       //一个Int型最大存这么大的量
       Int const MAX = 999999999;        
       //-------------------------------------------
       //某进制的基数。
       Int const RADIX = MAX + 1;       
       //-------------------------------------------
       //十进制基数 RADIX_SHI
       Int RADIX_SHI = ( ( 2 + 3 ) + ( 2 + 3 ) );
       //-------------------------------------------
       //多项式的项的总量
       int const Way = 5;//是5时，一个5项式。
       //-------------------------------------------
       //一个负一常量，不用 --， 用 +-1。
       int const  NEG = -1;
       //-------------------------------------------
       //字符'0'的常量名：CHAR_ZERO
       char const CHAR_ZERO = '0';
}
//-------------------------------------------
int StringToInteger( /*IN*/char const *const pch, /*OUT*/ligongbinde::Int vA[223] ) {
       //   pd( pointer dight)
       //      +987654321
       //                         pe(pointer end);
       char const *pd = pch;
       char const *pe = pch;
       if (*pd == '+' || *pd == '-') {
              pd++;
       }
       while (*pe)
       {
              pe++;
       }
       int idx = 0;
       while (pe > pd) {
              //认内存 办索引 取值
              ligongbinde::Int R = 1, V = 0;
              int n = ligongbinde::TOTAL;
              while (pe > pd && n > 0) {
                     V = ( ( --pe )[int()] + -ligongbinde::CHAR_ZERO ) * R + V;
                     R = R * ligongbinde::RADIX_SHI;
                     n = n + ligongbinde::NEG;
              }
              vA[idx] = V;
              idx++;
       }
       return idx;
}
//-------------------------------------------
void
Suan23WayMultiply(/**/ ligongbinde::Int A[2 + 3], /**/ligongbinde::Int B[2 + 3], /**/ligongbinde::Int C[2 + 3 + 2 + 3] ) {
       C[0] += +A[0] * B[0];
       C[1] += +A[0] * B[1] + A[1] * B[0];
       C[2] += +A[0] * B[2] + A[1] * B[1] + A[2] * B[0];
       C[3] += +A[0] * B[3] + A[1] * B[2] + A[2] * B[1] + A[3] * B[0];
       C[4] += +A[0] * B[4] + A[1] * B[3] + A[2] * B[2] + A[3] * B[1] + A[4] * B[0];
       C[5] += +A[1] * B[4] + A[2] * B[3] + A[3] * B[2] + A[4] * B[1];
       C[6] += +A[2] * B[4] + A[3] * B[3] + A[4] * B[2];
       C[7] += +A[3] * B[4] + A[4] * B[3];
       C[8] += +A[4] * B[4];
       C[9] += 0;
}
//-------------------------------------------
void
SuanCarray( /**/ligongbinde::Int C[2 + 3 + 2 + 3], int iC1, int iC2 ) {

       for (int iC = iC1; iC < iC2; iC++) {

              ligongbinde::Int High = C[iC] / ligongbinde::RADIX;
              ligongbinde::Int Low = C[iC] % ligongbinde::RADIX;
              C[iC] = Low;
              C[iC + 1] += High;

       }
}
void
Zero( /**/ligongbinde::Int V[], int nV ) {
       for (int i = 0; i < nV; i++) {
              V[i] = ligongbinde::Int();
       }
}
//-------------------------------------------
void SuanMultiply(/**/ligongbinde::Int A[], int iA1,int iA2,/**/ligongbinde::Int B[], int iB1, int iB2, /**/ligongbinde::Int C[] ,int nC ) {
       auto Min = []( int a, int b ) ->int { return ( a <= b ? a : b ); };
       int nA = iA2 - iA1;
       int nB = iB2 - iB1;
       for (int iA = iA1; iA < iA2; iA+= ligongbinde::Way) {
              for (int iB = iB1; iB < iB2; iB+= ligongbinde::Way ) {
                     Suan23WayMultiply( &A[iA], &B[iB], &C[iA + iB] );
              }
              SuanCarray( C, iA + iB1, Min( iA+nB+ ligongbinde::Way,nC) );
       }
}
#include <iostream>
#include <iomanip>
//-------------------------------------------
//命名代码区：函式名print
void print( ligongbinde::Int V[100], int nV ) {
       int iV = nV;
       while (V[iV] == 0)--iV;
       std::cout << std::setw(1) << V[iV];
       while (--iV >= 0) {
              std::cout << std::setw( ligongbinde::TOTAL ) << std::setfill( '0' ) << V[iV];
       }
       std::cout << std::endl;
}
//-------------------------------------------
void print( char const*const ch) {
       std::cout << std::setw( 1 ) << std::setfill( ' ' ) << ch;
}


void Run();
//-------------------------------------------
void  CcnRun() {
       while (123==123)Run();
}



//-------------------------------------------
void  Run() {
       ligongbinde::Int  D[100] = {}, E[100] = {}, F[200] = {};
       int nD, nE, nF;
       {
              std::string a, b;

              std::cout << "录入两个量:" << std::endl;
              std::cin >> a >> b;
              nD = StringToInteger(a.c_str(), D);
              nE = StringToInteger(b.c_str(), E);
              nF = nE + nD;
       }
       {
              SuanMultiply(D, 0, nD, E, 0, nE, F, nF);
              print("=\r\n");
              print(F, nE + nD);
       }
}



















































































//====---
//中国 广西 全州人 李公斌学士 。
// 2023年223日： 用多项式的乘理，计算二个大数的 乘值。
//夫大办事 大功一件 用计算机算量：
//首先起步学习C语言， 并且学而时习之， 
//然后 准备电力，计算机及编译器，
//再后 备好 衣装，食品，饭菜，
//最后用计算机写代码算量，分四步： 
//接收录入的量 ， 分内存 存量 ，用某原理计算量，在显示器上显示量。
// 写代码 
// 用(231):   +1 
// 用(232):   +2 
// 用(2323): ++  
// 用(236):   +-