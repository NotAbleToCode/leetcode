// 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

// 示例:

// 输入: 3
// 输出: 5
// 解释:
// 给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

#include<iostream>
#include<vector>
using namespace std;

// 二叉搜索树，是指左边子树的所有结点都要小于根结点，右边子树的所有结点都要大于根结点
// 那么，任意连续n个整数组成的二叉搜索树的结构个数是一样的
// 令f(n)为连续n个整数组成的二叉搜索树的结构个数
// 定义f(0)=1，易知f(1)=1
// 那么，对f(n)，依次选取结点作为根结点，则有f(n)=f(0)*f(n-1)+f(1)*f(n-2)+......+f(n-2)*f(1)+f(n-1)*f(0)

int numTrees(int n) {
    if(n==0){
        return 0;
    }
    vector<int> f(n+1, 0);
    f[0] = 1;
    f[1] = 1;
    for(int i=2;i<=n;i++){
        for(int q=0;q<i;q++){
            f[i] += f[q]*f[i-q-1];
        }
    }
    return f[n];
}

int main(){
    cout<<numTrees(3)<<endl;
}