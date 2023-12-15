#include "class_72.h"
#include <map>

#include <chrono>
#include <thread>

using namespace std;

void func(int questionNum);
void func72();
void func2697();
void func2008();

int main(int argc, char** argv)
{
    // ::testing::InitGoogleTest();
    // // 创建并添加自定义监听器
    // ::testing::TestEventListeners& listeners = ::testing::UnitTest::GetInstance()->listeners();
    // CustomTestListener* listern_ptr = new CustomTestListener();
    // listeners.Append(listern_ptr);

    // // ::testing::GTEST_FLAG(filter) = "q72.q";
    // ::testing::GTEST_FLAG(filter) = "q2697.q";
    // RUN_ALL_TESTS();
    // cout << listern_ptr->failtests << endl;
    func2008();
    system("Pause");
    return 0;
}

// TEST(q72, q){
//     Solution72 s72;
//     EXPECT_EQ(s72.minDistance(word1, word2), 2);
//     EXPECT_EQ(s72.minDistance(word1, word2), s72.minDistance(word1, word2) + 1);
//     EXPECT_EQ(s72.minDistance(word1, word2), 1);
// }

// TEST(q2697, q){
//     Solution2697 s2697;
//     EXPECT_EQ(s2697.makeSmallestPalindrome("egcfe"), "efcfe");
//     EXPECT_EQ(s2697.makeSmallestPalindrome("abcd"), "abba");
//     EXPECT_EQ(s2697.makeSmallestPalindrome("seven"), "neven");
//     EXPECT_EQ(s2697.makeSmallestPalindrome("c"), "c");
// }


void func(int questionNum){
    if (questionNum == 72){
        func72();
    }
    if (questionNum == 2697){
        func2697();
    }
}

void func72(){
    int a=0;
}

void func2697(){
    Solution2697 s2697;
    string s = "egcfe";
    string res = s2697.makeSmallestPalindrome(s);

    EXPECT_EQ(s2697.makeSmallestPalindrome("egcfe"), "efcfe");
    EXPECT_EQ(s2697.makeSmallestPalindrome("abcd"), "abba");
    EXPECT_EQ(s2697.makeSmallestPalindrome("seven"), "neven");
    EXPECT_EQ(s2697.makeSmallestPalindrome("c"), "c");

    cout << res << endl;
}

void func2008(){
    Solution2008 s2008;
    vector<vector<int>> rides1 {{2,5,4}, {1,5,1}};
    vector<vector<int>> rides2 {{1,5,1}, {2,5,4}};
    vector<vector<int>> rides3 {{1,6,1}, {3,10,2}, {10,12,3}, {11,12,2}, {12,15,2}};
    vector<vector<int>> rides4 {{1,6,1}, {3,10,2}, {10,12,3}, {11,12,2}, {12,15,2}, {13,18,1}};
    vector<vector<int>> rides5 {{2,3,6},{8,9,8},{5,9,7},{8,9,1},{2,9,2},{9,10,6},{7,10,10},{6,7,9},{4,9,7},{2,3,1}};
    cout << s2008.maxTaxiEarnings(10, rides1) << endl; 
    cout << s2008.maxTaxiEarnings(10, rides2) << endl; 
    cout << s2008.maxTaxiEarnings(10, rides3) << endl; 
    cout << s2008.maxTaxiEarnings(10, rides4) << endl; 
    cout << s2008.maxTaxiEarnings(10, rides5) << endl; 
}
