/*
***SPIELTABLE***
Nachname: Abdul Moeed
Vorname: Muhammad
*/


#include <iostream>

using namespace std;


struct table
{
    int points, match_done;
    char team_name[30];

};

struct table match[100];
int index_arr[2], points_arr[2], n_team;


void in_func(table match[100],int n_team)
{
    for (int i=1; i<=n_team;i++)
    {
       if (i==1)
       {
           cout<< "\n\n"<< "\t\tInput Teams\n\t\t***********\n\t\t***********\n";
       }
       cout<<"team "<<i<<": ";
       cin>>match[i-1].team_name;
       match[i-1].points = 0;
       match[i-1].match_done = 0;
    }
}


void out_func(table match[100], int n_team)
{

        if ((match[1].points == 0) && (match[1].points == 0))
        {
            std::cout<< "\n\n"<< "\t\tInitial Rankings\n\t\t****************\n\t\t****************\n";

        }
        else
        {
            std::cout<< "\n\n"<< "\t\tRankings\n\t\t********\n\t\t********\n";

        }
            cout<<"points\t"<< "done matches\t" << "teams\n";
        for (int j=1;j<=n_team;j++)
        {
            cout<<match[j-1].points<<"\t"<<match[j-1].match_done<<"\t\t"<<match[j-1].team_name<<"\n";

        }


}


int select_func(table match[100],int n_team)
{

            int a;
            if(index_arr[0] == 0)
            {
                std::cout<< "Please choose team?";
            }
            else
            {
                cout<<"Please choose team 2?";
            }


            std::cout<< "\n\n"<< "\t\tTeams\n\t\t*****\n\t\t*****\n";
            for(int k=1;k<=n_team;k++)
                {
                    std::cout<< k << "\t" << match[k-1].team_name << "\n";
                }
            std::cout<<"choose team by number: ";
            cin>>a;
            return a;
}

store_func(table match[100],int n_team,int index_arr[2],int points_arr[2])
{
    for(int p=1;p<=n_team;p++)
    {
        if (p==index_arr[0])
        {
            match[p-1].points += points_arr[0];
            match[p-1].match_done += 1;
        }
        if (p==index_arr[1])
        {
            match[p-1].points += points_arr[1];
            match[p-1].match_done += 1;
        }
    }

    for (int q=0;q<n_team;q++)
    {
        int temp1,temp2;
        for(int r=0;r<n_team-q-1;r++)
        {
            if(match[r].points<match[r+1].points)
            {
                temp1 = match[r].points;
                temp2 = match[r].match_done;
                match[r].match_done = match[r+1].match_done;
                match[r].points = match[r+1].points;
                match[r+1].points = temp1;
                match[r+1].match_done = temp2;
                swap(match[r].team_name,match[r+1].team_name);
            }
        }
    }
}
void reset_func(table match[100],int n_team)
{
  for (int m=0;m<n_team;m++)
  {
      match[m].points = 0;
      match[m].match_done = 0;
  }

}



int main(void)
{    struct table match[100];
    int choice, points_arr[2], index_arr[2],x,y;
    index_arr[0]= 0;
    std::cout<< "Enter number of teams: ";
    std::cin>>n_team;
    in_func(match,n_team);
    out_func(match,n_team);
    cout<<"\n0 end\n1 add result of a match\n2 show ranking\n9 reset points\nyour choice: ";
    cin>>choice;
    while (choice != 0)
    {


        switch(choice)
        {
            case 1:

                index_arr[0] = select_func(match,n_team);
                index_arr[1] = select_func(match,n_team);
                x=index_arr[0];
                y=index_arr[1];
                if (x!=y)
                {
                    string colon = ":";
                    cout<< "input as [points of "<<match[x-1].team_name<<"]"<<" : "<<"[points of "<<match[y-1].team_name<<"]? ";
                    cin>>points_arr[0]>> colon >>points_arr[1];
                    store_func(match,n_team,index_arr,points_arr);
                }
                else
                {
                        cout<<"*** sorry teams need to be different ***";
                }

                break;

            case 2:

                out_func(match,n_team);
                break;

            case 9:
                reset_func(match,n_team);
                break;
            default:
                cout<<"\n*** please enter the choice between 0, 1, 2 and 9 ***\n";
                break;

        }
        cout<<"\n0 end\n1 add result of match\n2 show ranking\n9 reset points\nyour choice: ";
        cin>>choice;
    }

return 0;


}



