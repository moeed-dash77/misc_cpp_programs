/*
Aufgabe: Hashfunktion
Nachname: Abdul Moeed
Vorname: Muhammad
*/



#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;


struct Entry
{
    string key;
    string value;

}hash_table[1];

int *x = new int();

int hash_func(string t)
{

    int b1,b2,hash_val,i=0;
    while(t[i+1] != '\0')
    {
        if (i==0)
        {
           b1=(int)t[i];
           b2=(int)t[i+1];
           hash_val = ((b1*128)+b2) % (*x)   ;
        }
       else
       {

           b2 = (int)t[i+1];
           hash_val = ((hash_val*128)+b2) % (*x) ;
       }
        i++;
    }

    return hash_val;
}


void insert_func(string a,string b,Entry hash_table[1])
{
    int index,counter=0;
    index = hash_func(a);
    if (hash_table[index].key.empty())
    {
        hash_table[index].key = a;
        hash_table[index].value = b;
    }
    else
    {
        while(!hash_table[index].key.empty() && counter==0)
        {
            if(index==(*x))
            {
                counter++;
                index=-1;
            }
            index++;
        }
        hash_table[index].key = a;
        hash_table[index].value = b;
    }

}

string hash_search(string a,string b,Entry hash_table[1])
{
    int index=0;
    while(index<=(*x))
    {
        if(hash_table[index].key == a)
        {
            b = hash_table[index].value;
            break;
        }
        else
        {
            index++;
            if(index==(*x))
            {
                b="Sorry the result couldn't be found\n";
                break;
            }
        }
    }
    return b;
}

void file_func(string orig_file,Entry hash_table[1])
{
    char reader,seperator=';';

    ifstream inFile;

    inFile.open(orig_file);

    cout<<"File is opened"<<endl;

    string reader_key,reader_value;


    while((reader = inFile.get()) != EOF)
    {
        reader_key="";
        while(reader != seperator)
        {

            reader_key = reader_key + reader;
            reader = inFile.get();

        }
        reader_value="";
        reader=inFile.get();
        while((reader != '\n') && (reader != EOF))
        {

            reader_value = reader_value + reader;
            reader = inFile.get();
        }

        insert_func(reader_key,reader_value,hash_table);

    }

     inFile.close();

    cout<<"File is closed"<<endl;
}

int main()
{

    string vocable,filename,translated;
    int p;
    cout<<"Please input value for (prime) number p: ";
    cin>> p;
    *x = p;
    struct Entry hash_table[p];
    cout << "Input file name: "<<endl;
    cin>> filename;

    file_func(filename,hash_table);

    while(vocable != "0")
    {
        cout<< "\n"<<"translate (0 for end): "<<endl;
        cin>>vocable;
        if(vocable == "0")
        {
            break;
        }
        else
        {
            translated = hash_search(vocable,"",hash_table);
            cout<<translated;
        }

    }

    return 0;
}

