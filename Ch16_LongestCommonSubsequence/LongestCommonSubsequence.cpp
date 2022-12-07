//  LongestCommonSubsequence.cpp
//  Created by rick
//  4/18/2013 8:18:52 PM

//  File lcs.cpp

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include "stopwatch.h"

using std::string;

typedef std::vector<std::vector<int>> Table;

string LCS_brute_force(const string& X, const string& Y) {
    //std::cout << "BF: " << X << " " << Y << '\n';
    string result = "";
    int xlen = X.length(), ylen = Y.length();
    if (xlen > 0 && ylen > 0) {
        string Xrest = X.substr(1, xlen - 1),
               Yrest = Y.substr(1, ylen - 1);
        if (X[0] == Y[0])
            result = X[0] + LCS_brute_force(Xrest, Yrest);
        else {
            string X_Yrest = LCS_brute_force(X, Yrest),
                   Xrest_Y = LCS_brute_force(Xrest, Y);
            //  Choose longest
            result = (X_Yrest.length() > Xrest_Y.length()) ?  X_Yrest : Xrest_Y;   
        }
    }
    return result;
}

void dumpTable(const string& X, const string& Y, const Table table) {
    //  Print column header
    std::cout << "       ";
    for ( size_t i = 0; i < Y.length(); i++ )   //each (var ch in Y)
        std::cout << Y[i] << ' ';   //"{0,2}", ch;
    std::cout << '\n';
    std::cout << "   +---------------+" << '\n';
    //  Print each row
    for (size_t r = 0; r < table.size(); r++) {
        if (r > 0)
            std::cout << ' ' << X[r - 1] << " | ";
        else
            std::cout << "   | ";
        for (size_t c = 0; c < table[r].size(); c++)
            std::cout << table[r][c] << ' ';
        std::cout << "|" << '\n';
    }
    std::cout << "   +---------------+" << '\n';
    std::cout << '\n';
}

Table LCS_table(const string& X, const string& Y) {
    int m = X.length(), n = Y.length();
    //  (m + 1) X (n + 1) table, filled with zeros
    Table C(m + 1, std::vector<int>(n + 1, 0));

    //dumpTable(X, Y, C);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (X[i] == Y[j])
                C[i + 1][j + 1] = C[i][j] + 1;
            else
                C[i + 1][j + 1] = std::max(C[i + 1][j], C[i][j + 1]);
			//  Uncomment the following three lines to get 
			//  intermediate output
            /*dumpTable(X, Y, C);
            char ch;
            cin.get(ch);*/
        }
    }
    return C;
}

string back_trace(const Table& C, const string& X, 
                  const string& Y, int i, int j) {
    if (i < 0 || j < 0)
        return "";
    else if (X[i] == Y[j])
        return back_trace(C, X, Y, i - 1, j - 1) + X[i];
    else {
        if (C[i + 1][j] > C[i][j + 1])
            return back_trace(C, X, Y, i, j - 1);
        else
            return back_trace(C, X, Y, i - 1, j);
    }
}

string LCS_dynamic_programming(const string& X, const string& Y) {
    Table table = LCS_table(X, Y);
    dumpTable(X, Y, table);
    return back_trace(table, X, Y, X.length() - 1, Y.length() - 1);
}

//  Highlights the characters of seq2 within seq1
static void highlight(const string& seq1, const string& seq2) {
    size_t pos1 = 0, pos2 = 0;
    std::cout << seq1 << '\n';
    while (pos1 < seq1.length()) {
        if (pos2 < seq2.length() && seq1[pos1] == seq2[pos2]) {
            std::cout << '^';
            pos2++;
        }
        else
            std::cout << ' ';
        pos1++;
    }
    std::cout << '\n';
}

void compare_BruteForceVsDynamicProgramming(string seq1, string seq2) {
    Stopwatch timerBF, timerDP;
    string ssBF, ssDP;
    timerBF.start();
    ssBF = LCS_brute_force(seq1, seq2);
    timerBF.stop();
    timerDP.start();
    ssDP = LCS_dynamic_programming(seq1, seq2);
    timerDP.stop();
    std::cout << seq1 << '\n';
    std::cout << seq2 << '\n';
    std::cout << ssBF << ' ' << ssBF.length() << ' ' <<
        timerBF.elapsed() << ' ' << '\n';
    std::cout << ssDP << ' ' << ssDP.length() << ' ' <<
        timerDP.elapsed() << ' ' << '\n';
    std::cout << '\n';
    highlight(seq1, ssBF);
    highlight(seq2, ssBF);
    std::cout << '\n';
    highlight(seq1, ssDP);
    highlight(seq2, ssDP);
    
}


int main() {
    Stopwatch timerBF, timerDP;

    compare_BruteForceVsDynamicProgramming("ABCBDAB", "BDCABA");
    std::cout << "------------------" << '\n';
    compare_BruteForceVsDynamicProgramming("ACAACCGTGAGTTATTCTAGAA",
                                           "CACCCCTAACCTTCTGGTTC");
    compare_BruteForceVsDynamicProgramming("ACAACCGAGAA",
                                           "CACCTCTGGTTC");
    std::cout << "------------------" << '\n';
    compare_BruteForceVsDynamicProgramming("ATCTGA", "CATTTA");

    //string A = "AAACCGTGAGTTATTCGTTCTAGAA";
    //string B = "CACCCCTAAGGTACCTTTGGTTC";
}

