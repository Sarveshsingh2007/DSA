#include<iostream>
#include<cstring>
using namespace std;

// bool mystrcmp(char str1[], char str2[]){
//     if(strlen(str1) != strlen(str2)) return false;

//     for(int i=0;i<strlen(str1);i++){
//         if(str1[i] != str2[i]) return false;
//     }
//     return true;
// }

int main(){
    //---------------LENGTH-----------------------

//     char name[100];
//     cin>>name;
//     int len = strlen(name);
//     cout<<"Length is: "<<len<<endl;

    //----------------------compare 2 strings---------------------
    // char str1[100];
    // char str2[100];
    // cout<<"Enter 1st string: ";
    // cin>>str1;
    // cout<<"Enter 2nd string: ";
    // cin>>str2;
    
    // if(strcmp(str1, str2) == 0){
    //     cout<<"equal"<<endl;
    // }else{
    //     cout<<"not equal"<<endl;
    // }


    //----another method-----
    // char str1[100];
    // char str2[100];
    // cout<<"Enter 1st string: ";
    // cin>>str1;
    // cout<<"Enter 2nd string: ";
    // cin>>str2;

    // if(mystrcmp(str1, str2)){
    //     cout<<"equal"<<endl;
    // }else{
    //     cout<<"not equal"<<endl;
    // }




    //-------------COPY STRING FUNCTION--------------------

    // char a[100];
    // char b[100];
    // cout<<"value of a: ";
    // cin>>a;
    // cout<<"copy of a in b is: "<<strcpy(b,a)<<endl;
    // cout<<"value of a after new value: "<<strcpy(a, "hello");


    //---------------------Str n cpy------------------------

    // copy first n char
    // strcpy(str1, str2)

    // char a[100];
    // char b[100];
    // cout << "value of a: ";
    // cin >> a;
    // strncpy(b, a, 3);
    // b[3] = '\0';   // ensure string ends properly
    // cout << "copy of a in b is: " << b << endl;
    // return 0;

    //-------another way of strncpy manually--------------

    // char a[100];
    // char b[100];
    
    // int n=3;
    // cout<<"value of a: ";
    // cin>>a;
    // int i;
    // for( i=0;i<n && a[i]!= '\0';i++){
    //     b[i] = a[i];
    // }
    // b[i] = '\0'; // null terminate destination

    // cout<<"copy of a in b is: "<<b<<endl;



    //---------------------------strcat()---------------------
    // char firstname[100];
    // char lastname[100];
    // cout<<"Enter first name: ";
    // cin>>firstname;
    // cout<<"Enter last name: ";
    // cin>>lastname;

    // cout<<"Full name: "<<strcat(firstname, lastname)<<endl;

    //-------another way of strcat() manually----------

    char firstname[100];
    char lastname[100];

    cout << "Enter first name: ";
    cin >> firstname;

    cout << "Enter last name: ";
    cin >> lastname;

    int i = 0;
    // move i to end of firstname
    while (firstname[i] != '\0') {
        i++;
    }

    // add space
    firstname[i] = ' ';
    i++;

    int j = 0;
    // copy lastname
    while (lastname[j] != '\0') {
        firstname[i] = lastname[j];
        i++;
        j++;
    }

    firstname[i] = '\0';   // VERY IMPORTANT

    cout << "Full name: " << firstname << endl;


    return 0;
}