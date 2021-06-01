#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <cmath>

using namespace std;

struct Cards
{
    int rankk; //rank of the cards
    string suit; //suit of the cards

};
int main()
{
    srand(time(0));
    string ss; //to read the file
    int k=0;
    int j=0;
    Cards store[52]; //Store the values from the file give A1deck
    Cards p1[3];  //Cards of Player 1
    Cards p2[3]; //Cards of Player 2
    ifstream myDeck; //Opening the file and reading it
    myDeck.open("A1deck.txt");
    int new12=0;

    for(int i=0; i<104; i++)
    {
        myDeck>>ss;

        if(i==0||i==2||i==4||i==6||i==26||i==28||i==30||i==32||i==52||i==54||i==56||i==58||i==78||i==80||i==82||i==84)
        {
            if(i==0||i==26||i==52||i==78)
            {
                store[k].rankk=14; //Store the Ace rank as 14
            }
            else if(i==2||i==28||i==54||i==80)
            {
                store[k].rankk=13;//Store the King rank as 13
            }
            else if(i==4||i==30||i==56||i==82)
            {
                store[k].rankk=12;//Store the Queen rank as 12
            }
            else if(i==6||i==32||i==58||i==84)
            {
                store[k].rankk=11;//Store the Jack rank as 11
            }
            k++;
        }

        else if(i%2==0&&i!=2&&i!=4&&i!=6&&i!=26&&i!=28&&i!=30&&i!=32&&i!=52&&i!=54&&i!=56&&i!=58&&i!=78&&i!=80&&i!=82&&i!=84)
            {
                //Storing 10,9,8,7,6,5,4,3,2 into struck rankk.
            stringstream new1(ss);
            new1>>new12;
            if(new12!=0)
            store[k].rankk=new12;
            k++;

            }
        else if(i%2!=0)
            {
                //Storing suit of Deck in struct suit
            store[j].suit=ss;
            j++;
            }

    }
    myDeck.close(); //closing the file

        cout<<setw(60)<<"The TeenPatti has Started"<<endl;
        cout<<endl;
        cout<<endl;

        string name1;
        cout<<"Write the name of Player one "<<endl;
        cin>>name1;

        string name2;
        cout<<endl;
        cout<<"Write the name of Player two "<<endl;
        cin>>name2;

        cout<<endl;

        char select;//Does Player want to play or not

        cout<<"Do you want to distribute cards (y/n)"<<endl;
        cin>>select;
        cout<<endl;

        int slect=0;
        int vlue=1; //To check the condition that three rounds done or not
        int Wc1=0;//Player 1 winning times
        int wc2=0;//Player 2 winning times
        char CoN;//Do Player one want to cheat
        int cheatvalue=rand()%52;//random value generated when cheating
do{

    if(select=='y')
{
        int x=0;
        if(vlue==3)
        {//when round 3 is going to start
            cout<<"Player 2 do you want to cheat in this round? (y/n) "<<endl;
            cin>>CoN;
        }

        cout<<"\nGame Started"<<endl;
        cout<<"Cards distributed"<<endl;
        cout<<endl;
        while(x<3)
    {
        int r1value=rand()%52; //Player 1 random value generated
        int r2value=rand()%52; //Player 2 random value generated
        p1[x].rankk=store[r1value].rankk;//Player 1 rank stored
        p1[x].suit=store[r1value].suit;//Player 1 suit stored
        p2[x].rankk=store[r2value].rankk;//Player 2 rank stored
        p2[x].suit=store[r2value].suit;//Player 2 suit stored
        x++;//three cards store
    }
    for(int b=0; b<3; b++)
    {
        //Sorting the rank values
        //p1[0]>p1[1]>p1[2]
        //p2[0]>p2[1]>p2[2]
            for(int a=b; a<3; a++)
            {
                if(p1[a].rankk>p1[b].rankk)
                {
                    int x= p1[b].rankk;
                    p1[b].rankk=p1[a].rankk;
                    p1[a].rankk=x;
                }

                if(p2[a].rankk>p2[b].rankk)
                {
                    int y= p2[b].rankk;
                    p2[b].rankk=p2[a].rankk;
                    p2[a].rankk=y;
                }

            }
    }

    cout<<"Cards of player one are\n "<<endl;

    for(int q=0; q<3; q++)
    {
        //printing out cards of Player 1
        if(p1[q].rankk!=14&&p1[q].rankk!=11&&p1[q].rankk!=12&&p1[q].rankk!=13)

        { //when rank is 2-10
            cout<<p1[q].rankk<<" "<<p1[q].suit<<endl;
        }

        else if(p1[q].rankk==14)

        {//when rank is Ace
            cout<<"Ace "<<p1[q].suit<<endl;
        }

        else if(p1[q].rankk==11)

        {//when rank is jack
            cout<<"Jack "<<p1[q].suit<<endl;
        }
        else if(p1[q].rankk==12)

        {//when rank is queen
            cout<<"Queen "<<p1[q].suit<<endl;
        }

        else if(p1[q].rankk==13)

        {//when rank is king
            cout<<"King "<<p1[q].suit<<endl;}
    }

        cout<<"\ncards of player two are \n"<<endl;

    for(int j=0; j<3; j++)
    {
        //Printing out cards of Player 2
        if(p2[j].rankk!=14&&p2[j].rankk!=11&&p2[j].rankk!=12&&p2[j].rankk!=13)

        {//When rank is 2-10
            cout<<p2[j].rankk<<" "<<p2[j].suit<<endl;
        }

        else if(p2[j].rankk==14)

        {//when rank is ace
            cout<<"Ace "<<p2[j].suit<<endl;
        }

        else if(p2[j].rankk==11)

        {//When rank is jack
            cout<<"Jack "<<p2[j].suit<<endl;
        }

        else if(p2[j].rankk==12)

        {//When rank is queen
            cout<<"Queen "<<p2[j].suit<<endl;
        }

        else if(p2[j].rankk==13)

        {//When rank is King
            cout<<"King "<<p2[j].suit<<endl;
        }
    }

    if(CoN=='y')
  {
        //When Player 2 decided to cheat
        cout<<"\nCards of Player 2 after swapping\n"<<endl;

        p2[2].rankk=p2[cheatvalue].rankk;
    for(int j=0; j<3; j++)
    {
        //Printing card after Swapping
        if(p2[j].rankk!=14&&p2[j].rankk!=11&&p2[j].rankk!=12&&p2[j].rankk!=13)

        { //When Swapped Value is 2-10
            cout<<p2[j].rankk<<" "<<p2[j].suit<<endl;
        }

        else if(p2[j].rankk==14)
        {//When Swapped card is Ace
            cout<<"Ace "<<p2[j].suit<<endl;
        }

        else if(p2[j].rankk==11)

        {//When Swapped card is jack
            cout<<"Jack "<<p2[j].suit<<endl;
        }

        else if(p2[j].rankk==12)

        {//When swapped is queen
            cout<<"Queen "<<p2[j].suit<<endl;
        }

        else if(p2[j].rankk==13)

        {//When Swapped card is king
            cout<<"King "<<p2[j].suit<<endl;
        }
    }
  }

}
    else
    {
        cout<<"Game not Played"<<endl;
        return 0;
    }


    cout<<endl;
    int wincon=0;//Wining condition
    //The below conditions are to check
    //whether three cards are same or not
    if((p1[0].rankk==p1[1].rankk&&p1[0].rankk==p1[2].rankk)&&(p2[0].rankk!=p2[1].rankk||p2[0].rankk!=p2[2].rankk))
    {//When rank of all the cards of player 1 are same
        //and card of player two are different
        cout<<" Winner is "<<name1;
        Wc1++;
        wincon=1;
    }
    else if((p1[0].rankk==p1[1].rankk&&p1[0].rankk==p1[2].rankk)&&(p2[0].rankk==p2[1].rankk&&p2[0].rankk==p2[2].rankk)&&(p1[0].rankk>p2[0].rankk))
    {//When rank of all the cards of player 1 are same
        //and card of player two are also same
        //player one cards are greater than player two cards
        cout<<" Winner is "<<name1;
        Wc1++;
        wincon=1;
    }
    else if((p2[0].rankk==p2[1].rankk&&p2[0].rankk==p2[2].rankk)&&(p1[0].rankk==p1[1].rankk&&p1[0].rankk==p1[2].rankk)&&(p2[0].rankk>p1[0].rankk))
    {//When rank of all cards of player 2 are same
        //rank of cards are different for player 1
        cout<<" Winner is "<<name2;
        wc2++;
        wincon=1;
    }
    else if((p2[0].rankk==p2[1].rankk&&p2[0].rankk==p2[2].rankk)&&(p1[0].rankk!=p1[1].rankk||p1[0].rankk!=p1[2].rankk))
    {
        //When rank of all cards of player 2 are same
        //and all rank of cards player 1 are same
        //player two card is greater than player 1
        cout<<" Winner is "<<name2;
        wc2++;
        wincon=1;
    }
    if(wincon==0)//if above conditions are false
    {
        //Checking condition for difference of 1
        //example 10,9,8.

            if(((p1[0].rankk-p1[1].rankk==1&&p1[1].rankk-p1[2].rankk==1)||(p1[0].rankk-p1[1].rankk==11&&p1[1].rankk-p1[2].rankk==1))&&((p2[0].rankk-p2[1].rankk!=1||p2[1].rankk-p2[2].rankk!=1)&&(p1[0].rankk-p1[1].rankk!=11&&p1[1].rankk-p1[2].rankk!=1)))
            {
                cout<<"Winner is "<<name1;
                Wc1++;
            }

            else if(((p1[0].rankk-p1[1].rankk==1&&p1[1].rankk-p1[2].rankk==1)||(p1[0].rankk-p1[1].rankk==11&&p1[1].rankk-p1[2].rankk==1))&&(p2[0].rankk-p2[1].rankk==1&&p2[1].rankk-p2[2].rankk==1)&&(p1[0].rankk>p2[0].rankk))
            {
                cout<<"Winner is "<<name1;
                Wc1++;
            }

            else if(((p2[0].rankk-p2[1].rankk==1&&p2[1].rankk-p2[2].rankk==1)||(p2[0].rankk-p2[1].rankk==11&&p2[1].rankk-p2[2].rankk==1))&&(p1[0].rankk-p1[1].rankk!=1||p1[1].rankk-p1[2].rankk!=1))
            {
                cout<<"Winner is "<<name2;
                wc2++;
            }

            else if(((p2[0].rankk-p2[1].rankk==1&&p2[1].rankk-p2[2].rankk==1)||(p2[0].rankk-p2[1].rankk==11&&p2[1].rankk-p2[2].rankk==1))&&(p1[0].rankk-p1[1].rankk==1&&p1[1].rankk-p1[2].rankk==1)&&(p2[0].rankk>p1[0].rankk))
            {
                cout<<"Winner is "<<name2;
                wc2++;
            }
            //When suit of player 1 and 2 are same
            //color trait
            else if((p1[0].suit==p1[1].suit&&p1[0].suit==p1[2].suit)&&(p2[0].suit==p2[1].suit&&p2[0].suit==p2[2].suit))
            {

                        if(p1[0].rankk>p2[0].rankk)
                        {
                            cout<<"Winner is "<<name1;
                            Wc1++;
                        }
                        else if(p2[0].rankk>p1[0].rankk)
                        {
                            cout<<"Winner is "<<name2;
                            wc2++;
                        }

            }
            //when suit of player 1 cards are same
            //color trait
            else if((p1[0].suit==p1[1].suit&&p1[0].suit==p1[2].suit)&&(p2[0].suit!=p2[1].suit||p2[0].suit!=p2[2].suit))
                    {

                            cout<<"Winner is "<<name1;
                            Wc1++;

                    }
            //when suit of player 2 cards are same
            //color trait
            else if((p2[0].suit==p2[1].suit&&p2[0].suit==p2[2].suit)&&(p1[0].suit!=p1[1].suit||p1[0].suit!=p1[2].suit))
                    {

                            cout<<"Winner is "<<name2;
                            wc2++;
                    }
            //When two cards of player 1 are same
            //and all cards of player 2 are different
            else if((p1[0].rankk==p1[1].rankk||p1[0].rankk==p1[2].rankk||p1[1].rankk==p1[2].rankk)&&(p2[0].rankk!=p2[1].rankk&&p2[0].rankk!=p2[2].rankk&&p2[1].rankk!=p2[2].rankk))
                    {

                            cout<<"Winner is "<<name1;
                            Wc1++;
                    }

            //when two cards of player 2 are same
            //and all cards of player 1 are different

            else if((p2[0].rankk==p2[1].rankk||p2[0].rankk==p2[2].rankk||p2[1].rankk==p2[2].rankk)&&(p1[0].rankk!=p1[1].rankk&&p1[0].rankk!=p1[2].rankk&&p1[1].rankk!=p1[2].rankk))
                    {

                            cout<<"Winner is "<<name2;
                            wc2++;
                    }

        else
        {
            //The highest card wins
            if(p1[0].rankk>p2[0].rankk)
            {
                cout<<"Winner is Player "<<name1;
                Wc1++;
            }
            else if(p2[0].rankk>p1[0].rankk)
             {
                cout<<"Winner is Player "<<name2;
                wc2++;
             }
            else if(p2[0].rankk==p1[0].rankk)
            {

                if(p1[1].rankk>p2[1].rankk)
              {
                cout<<"Winner is Player "<<name1;
                Wc1++;
              }

                else if(p2[1].rankk>p1[1].rankk)
              {
                cout<<"Winner is Player "<<name2;
                wc2++;
              }

                else if(p2[1].rankk==p1[1].rankk)
                {

                if(p1[2].rankk>p2[2].rankk)
                {

                cout<<"Winner is Player "<<name1;
                Wc1++;
                }
                else if(p2[2].rankk>p1[2].rankk)
                {
                cout<<"Winner is Player "<<name2;
                wc2++;
                }
                }
        }
            else
            {
                cout<<"Match Draw"<<endl;
            }
        }
    }
    if(vlue<3)
    {
    cout<<"\n\nDo You Want to Play Round "<<vlue+1<<" (press 1 key to proceed, 2 to close)"<<endl;
    cin>>slect;
    if(slect!=1)
    {
        cout<<"\nMatch over"<<endl;
        break;
    }
    }
    vlue++;
}while(slect!=1||vlue<4);
    if(Wc1>wc2)
     {
         cout<<"\n\nOverall Winner is "<<name1<<endl;
     }
    else
      {

        cout<<"\n\nOverall Winner is "<<name2<<endl;
      }
    return 0;
}
