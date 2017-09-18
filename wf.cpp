#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <queue>
#include <algorithm>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fstream>
#include <vector>
#include <cctype>
#include <iomanip>
using namespace std;

std::map<string, int> mp;//map
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 10000
#define DEBUG cout << "debug" << endl
typedef pair<string,int> PAIR;
int cmp(const PAIR& x, const PAIR& y)//compare
{
    return x.second > y.second;
}
void puts_map(map<string,int> &mp)//Output
{
    map<string,int>::iterator it;
    for(it = mp.begin(); it != mp.end(); it ++)
    {
        cout << it -> first<<" "  << it -> second<< endl;
    }
}

void swap_c(char s[50]) //Swap
{
    int len = strlen(s);
    for(int i = 0,j = len-1; i < j ; i ++,j--)
    {
        char c;
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

struct Fn
{
    char s[50];
} fn[10];

int main(int argc,char *argv[])
{
    // -------------------get the filename
    system("cmd /c dir F:\\software\\*.txt /a-d /b /s >F:\\software\\output.txt");
    ifstream myfile("F:\\software\\output.txt");
    char buffer[1024];
    int Cnt = 0;
    while (! myfile.eof() )
    {
        myfile.getline (buffer,1024);
        int len = strlen(buffer);
        // char filename[50];
        int cnt = 0;
        bool tmp = false;
        // memset(filename,0,50);
        for(int i = len - 1; i >= 0 ; i --) //get the name of files
        {
            //cout << buffer[i] << endl;
            if(buffer[i] == '.')
            {
                for(int j = i-1; buffer[j] != '\\'; j --)
                {
                    fn[Cnt].s[cnt] = buffer[j];
                    cnt ++;
                }
            }
            //if(tmp) break;
        }
        //cout << buffer << endl;
        //--------- swap_c(filename);
        Cnt++;
    }
    for(int i = 0; i < Cnt-1 ; i ++)
    {
        swap_c(fn[i].s);
        strcat(fn[i].s,".txt");
    }
    //------upon :get the filename
//    if(strcmp("aa","aa") == 0)
//        DEBUG;
    vector<PAIR> vt;
    int num = 0;
    string s;
    string name;
    cin >> name;
    if(name == "folder")
    {
        for(int i = 1; i < Cnt-1; i ++)
        {
            num = 0;
            mp.erase(mp.begin(),mp.end());
            vt.erase(vt.begin(),vt.end());
            name = fn[i].s;
            cout << name << endl;
            ifstream fin(name.c_str());
            while(fin>>s)//input the file
            {
                int len=s.size();
                if (ispunct(s[len-1]))
                {
                    s.erase(len-1,1);
                }
                mp[s]++;
                if(mp[s] == 1)
                    num ++;
            }
            //sort
            for (map<string,int>::iterator curr = mp.begin(); curr != mp.end(); ++curr)
            {
                vt.push_back(make_pair(curr->first, curr->second));
            }
            sort(vt.begin(), vt.end(), cmp);
            //
            if(num == 1)
                printf("total 1 word\n");
            else if(num != 0)
                printf("total %d words\n",num);
            cout <<endl;
            for(int i = 0 ; i<(vt.size()>10?10:vt.size()); i++)
            {
                //printf("%-20s %d\n",vt[i].first,vt[i].second);
                cout<<vt[i].first<<" " ;
                cout <<vt[i].second << right<< endl;
            }

            cout << "---------------"<< endl;
            //cout << "~~~~~~~~~~~~~"<<endl;
            //puts_map(mp);
            //fin.close();
           // cin.get();
        }
    }
    else {
            num = 0;
            mp.erase(mp.begin(),mp.end());
            vt.erase(vt.begin(),vt.end());
    //cin.get();
    ifstream fin(name.c_str());//read the file named 'name'
    //  cout << name << endl;
    // The big change
    //GoDie
    while(fin>>s)//input the file
    {

        //DEBUG;
        int len=s.size();
        //cout <<s<<"~~"<< endl;
        if (ispunct(s[len-1]))
        {
            s.erase(len-1,1);
        }
        std::transform(s.begin(),s.end(),s.begin(),::tolower);
       // cout<<s<< endl;
        mp[s]++;
        if(mp[s] == 1)
            num ++;
    }
    //sort
    for (map<string,int>::iterator curr = mp.begin(); curr != mp.end(); ++curr)
    {
        vt.push_back(make_pair(curr->first, curr->second));
    }
    sort(vt.begin(), vt.end(), cmp);
    //
    if(num == 1)
        printf("total 1 word\n");
    else if(num != 0)
        printf("total %d words\n",num);
    cout <<endl;
    for(int i = 0 ; i<(vt.size()>10?10:vt.size()); i++)
    {
        cout<<vt[i].first<<" " <<vt[i].second << endl;
    }
    }
    //cout << "~~~~~~~~~~~~~"<<endl;
    //puts_map(mp);
//    fin.close();
  //  cin.get();
    return 0;
}







