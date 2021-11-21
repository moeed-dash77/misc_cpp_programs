#include <iostream>
#include <cmath>
using namespace std;

struct obstacles
{
    string name;
    float x,y;
    float distance;
    struct obstacles *next;

}*head;



float distance(struct obstacles *temp1, struct obstacles *temp2)
{
    float sqr1,sqr2,sum,d;
    sqr1 = (temp1->x) - (temp2->x);
    sqr2 = (temp2->y) - (temp2->y);
    sum = pow(sqr1,2) + pow(sqr2,2);
    d = pow(sum,0.5);
    return d;
}

obstacles* nearest_obst(struct obstacles *head, struct obstacles *nearest_ptr)
{
    struct obstacles *temp,*nearest_pt;
    temp = head;
    float least;
    if(temp == nullptr)
    {
        return temp;
    }
    else
    {
        nearest_pt = temp;
       while(temp != nullptr)
       {
           temp->distance = distance(temp,nearest_ptr);
            if ((temp->distance) != 0)
            {
                    if (temp->distance < nearest_pt->distance)
                  {
                     nearest_pt = temp;

                  }
            }


        temp = temp->next;

       }

    }


}

void new_obst(struct obstacles *head, struct obstacles *new_pt)
{
    new_pt->next = head;
    head = new_pt;

}

/*void print_list()
{

}
*/


int main()
{
    obstacle *head = nullptr
    obstacle *temp;
    temp = new obstacle;
    while ( == 'end')
    {
        cout << "string describing obstacle (\"end\" for end of input): ";
        cin >> temp->name;
        cout << "x and y coordinate: ";
        cin >> temp->x >> obst->y;
        distance(temp);
        if (head == nullptr)
        {
            head = temp;
        }
        else
        {
            new_obst(head,temp);

        }
        nearest_obst(head,p)

        obst.distance = //call distance function to find the distance of obstacle from center

    }

    //print list now, distance from centre, and nearest point;
    //...

    //Now delete the list
    //...

    return 0;
}
