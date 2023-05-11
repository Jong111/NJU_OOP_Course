//#include <iostream>
//#include <fstream>
//#include <iterator>
//#include<string>
//#include <algorithm>
//
//using namespace std;
//
//
//void operatingFile(string inputFile, string outputFile1, string outputFile2) {
//    ifstream input(inputFile); 
//    if (!input) {
//        cout << "Failed to open " << inputFile << endl;
//        return;
//    }
//
//    ofstream odd(outputFile1); 
//    if (!odd) {
//        cout << "Failed to open " << outputFile1 << endl;
//        return;
//    }
//
//    ofstream even(outputFile2); 
//    if (!even) {
//        cout << "Failed to open " << outputFile2 << endl;
//        return;
//    }
//
//    istream_iterator<int> in_iter(input); 
//    istream_iterator<int> eof; 
//    ostream_iterator<int> odd_iter(odd, " "); 
//    ostream_iterator<int> even_iter(even, "\n"); 
//
//    while (in_iter != eof) { 
//        int n = *in_iter++; 
//        if (n % 2 == 0) { 
//            *even_iter++ = n; 
//        }
//        else { 
//            *odd_iter++ = n; 
//        }
//    }
//
//    input.close(); 
//    odd.close(); 
//    even.close(); 
//}
//
//
//int main(int argc, char* argv[])
//{
//    operatingFile("inputFile.txt", "outputFile1.txt", "outputFile2.txt");
//    return 0;
//}