﻿//Cho Số tiền S, các loại tiền arr = {a,b,c,...,n}. Tìm cách đổi S từ các loại tiền có trong arr.
/*Ví dụ: S=5, arr = {5, 2 ,1} ==> có 4 cách đổi.
    5 = 5
    5 = 2 + 2 + 1
    5 = 2 + 1 + 1 + 1
    5 = 1 + 1 + 1 + 1
*/

#include <iostream>
#include <map>
#include<algorithm>
#include <vector>
using namespace std;

int atm(int, vector<int>); //Cách 2: lưu kết quả
int dem(int, vector<int>, map<int, int>);

int main()
{
    //int S = 5;
    int S;
    vector<int> arr = { 5,2,1 };
    do {
        cout << "S = ";
        cin >> S;
        cout << "So cach: " << atm(S, arr) << endl;
    } while (S > 0);
    
    return 0;
}

int atm(int S, vector<int> arr) { //vector arr[] -> tập hợp tiền lẻ
    map<int, int> check{};
    return dem(S, arr, check);
}

int dem(int S, vector<int> arr, map<int, int> check) { //check: kiểm trả cặp [S] - size() đã tính chưa.
    if (S == 0)
        return 1;
    if (S < 0 || arr.size() == 0)
        return 0;
    if (check[S] != arr.size()) //Nếu cặp S - size() chưa được tính
    {
        vector<int> temp;
        temp.assign(arr.begin(), arr.end() - 1); //tạo mảng giảm cuối
        return check[S] = dem(S - arr[arr.size() - 1], arr, check) + dem(S, temp, check);
        //atm(S - arr[arr.size() - 1], arr) + atm(S, temp);
    }
    return check.count(S); //nếu đã tồn tại thì trả về 1
}

//Note--> Kết quả đúng nhưng thời gian thực thi lâu hơn!!!!!!

//int atm(int S, vector<int> arr) { //vector arr[] -> tập hợp tiền lẻ
//    map<pair<int, int>, int> check{};
//    return dem(S, arr, check);
//
//}
//
//int dem(int S, vector<int> arr, map<pair<int, int>, int> check) { //check: kiểm trả cặp [S] - size() đã tính chưa.
//    if (S == 0)
//        return 1;
//    if (S < 0 || arr.size() == 0)
//        return 0;
//    map<pair<int, int>, int>::const_iterator it = check.find(make_pair(0, 0)); //it lưu vị trí của pair{S,arr.size()}
//    if (it == check.end()) { //nếu duyệt đến cuối vấn chưa xác định đc vị trí <==> chưa tồn tại pair{}
//        vector<int> temp;
//        temp.assign(arr.begin(), arr.end() - 1); //tạo mảng giảm cuối
//        check[{S, arr.size()}] = dem(S - arr[arr.size() - 1], arr, check) + dem(S, temp, check); //tính số cách của pair{S,arr.size()}
//        //atm(S - arr[arr.size() - 1], arr) + atm(S, temp);
//    }
//    return check[{S, arr.size()}];
//}
