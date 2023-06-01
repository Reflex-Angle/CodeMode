//Data record management of cricket players
//Organization of players based on a calculated points system
//Creating the best Playing 11 for a cricket match

/*
The user is required to input the player stats available from past matches and some demographic details
The user is also required to input performance details from the last 5 matches to take current form into consideration
This program stores the statistics of each players in class objects which can be accessed by the user
This program uses a statistical algorithm to estimate the value of a player using a points system
This program then displays the best playing 11 devised in a 5-2-4 batting order with a wicket keeper included
*/

#include <iostream>
#include <string>

using namespace std;

class Cricketer{
    public:
    string name;
    int age;
    int mat;//no of matches played
    char hand;//L for left handed and R for right handed
    int mom;//no of man of the match awards
    float last5pts;//points for performance in last 5 matches
    float total;
};

class Batsman : public Cricketer{
    public:
    int last5[5][2];//last 5 scores and no of balls
    float last5avg;
    float last5sr;
    float avg;//batting average
    float sr;//strike rate
    char wk;//Y for wicketkeeper and N for not
    float battotal;
    void find(){
        float runs=0;
        float balls=0;
        for (int i=0;i<5;i++){
            runs+=last5[i][0];
            balls+=last5[i][1];
        }
        last5avg=runs/5;
        last5sr=((runs/balls)*100);
        battotal=((avg*avg*mat*sr*last5avg*5*last5sr)/100000000+(mom*5)-(age*5));
        total=battotal;
    }
};

class Bowler : public Cricketer{
    public:
    int last5b[5][3];//last 5 wickets,runs given and balls bowled
    int wick;//no of wickets
    float econ;//economy rate
    string style;//bowling style
    float last5wick=0;
    float last5econ;
    float bowltotal;
    void findb(){
        float runs=0;
        float balls=0;
        for (int i=0;i<5;i++){
            last5wick+=last5b[i][0];
            runs+=last5b[i][1];
            balls+=last5b[i][2];
        }
        last5econ=((runs/balls)*6);
        bowltotal=(((((wick*wick)/(econ*econ))*(last5wick/last5econ))/10)*mat*5+(mom*5)-(age*5));
        total=bowltotal;
    }
};

class Allrounder : public Batsman{
    public:
    int last5b[5][3];//last 5 wickets,runs given and balls bowled
    int wick;//no of wickets
    float econ;//economy rate
    string style;//bowling style
    float last5wick=0;
    float last5econ;
    float bowltotal;
    void findb(){
        float runs=0;
        float balls=0;
        for (int i=0;i<5;i++){
            last5wick+=last5b[i][0];
            runs+=last5b[i][1];
            balls+=last5b[i][2];
        }
        last5econ=((runs/balls)*6);
        bowltotal=(((((wick*wick)/(econ*econ))*(last5wick/last5econ))/10)*mat*5+(mom*5)-(age*5));
        total=battotal+bowltotal;
    }
};

//Main Function

int main() {
    int n1,n2,n3;
    cout<<"Enter the number of batsmen (minimum 5), bowlers (minimum 2) and allrounders (minimum 4) being considered seperated by spaces respectively"<<endl;
    cin>>n1>>n2>>n3;
    if ((n1+n2+n3)<11){
        cout<<"Needs to be a minimum of 11 players";
        exit(0);
    }
    if ((n2+n3)<5){
        cout<<"Needs to be a minimum of 5 bowling options";
        exit(0);
    }

    Batsman bat[n1];
    Bowler bow[n2];
    Allrounder all[n3];

    //Batsmen stats input
    int wkcount=0;
    cout<<"List of Batsmen"<<endl;
    for(int i=0;i<n1;i++){
        cout<<"Enter the following seperated by spaces: Name, Age, Number of matches played (minimum 5), Dominant hand (L/R), Number of man of the match awards, average, strike rate and if he is a wicket keeper (Y/N) "<<endl;
        cin>>bat[i].name>>bat[i].age>>bat[i].mat>>bat[i].hand>>bat[i].mom>>bat[i].avg>>bat[i].sr>>bat[i].wk;
        for (int j=0;j<5;j++){
            string x;
            switch (j){
                case 0:
                x="last";
                break;
                case 1:
                x="2nd last";
                break;
                case 2:
                x="3rd last";
                break;
                default:
                x=to_string(j+1)+"th last";
            }
            cout<<"Enter the number of runs scored and number of balls faced in his "<<x<<" match"<<endl;
            cin>>bat[i].last5[j][0]>>bat[i].last5[j][1];
        }
        bat[i].find();
        if (bat[i].wk=='Y'){
            wkcount++;
        };
    }
    if (wkcount==0){
        cout<<"At least one wicket keeper must be included";
        exit(0);
    }

    //Bowlers stats input
    cout<<"List of Bowlers"<<endl;
    for(int i=0;i<n2;i++){
        cout<<"Enter the following seperated by spaces: Name, Age, Number of matches played (minimum 5), Dominant hand (L/R), Number of man of the match awards, wickets taken, economy rate, bowling style (Pace/Spin)"<<endl;
        cin>>bow[i].name>>bow[i].age>>bow[i].mat>>bow[i].hand>>bow[i].mom>>bow[i].wick>>bow[i].econ>>bow[i].style;
        for (int j=0;j<5;j++){
            string x;
            switch (j){
                case 0:
                x="last";
                break;
                case 1:
                x="2nd last";
                break;
                case 2:
                x="3rd last";
                break;
                default:
                x=to_string(j+1)+"th last";
            }
            cout<<"Enter the number of wickets taken, runs conceded and balls bowled in his "<<x<<" match"<<endl;
            cin>>bow[i].last5b[j][0]>>bow[i].last5b[j][1]>>bow[i].last5b[j][2];
        }
        bow[i].findb();
    }

    //Allrounders stats input
    cout<<"List of Allrounders"<<endl;
    for(int i=0;i<n3;i++){
        cout<<"Enter the following seperated by spaces: Name, Age, Number of matches played (minimum 5), Dominant hand (L/R), Number of man of the match awards, average, strike rate, wickets taken, economy rate, bowling style (Pace/Spin)"<<endl;
        cin>>all[i].name>>all[i].age>>all[i].mat>>all[i].hand>>all[i].mom>>all[i].avg>>all[i].sr>>all[i].wick>>all[i].econ>>all[i].style;
        for (int j=0;j<5;j++){
            string x;
            switch (j){
                case 0:
                x="last";
                break;
                case 1:
                x="2nd last";
                break;
                case 2:
                x="3rd last";
                break;
                default:
                x=to_string(j+1)+"th last";
            }
            cout<<"Enter the number of runs scored and number of balls faced in his "<<x<<" match"<<endl;
            cin>>all[i].last5[j][0]>>all[i].last5[j][1];
            cout<<"Enter the number of wickets taken, runs conceded and balls bowled in his "<<x<<" match"<<endl;
            cin>>all[i].last5b[j][0]>>all[i].last5b[j][1]>>all[i].last5b[j][2];
        }
        all[i].find();
        all[i].findb();
    }
    Batsman batlist[5]; //The 5 batsmen in the playing 11
    Batsman tbat;
    for (int i=0;i<n1+1;i++){
        for (int j=0;j<n1;j++){
            if (bat[j].total>bat[j+1].total){
                tbat=bat[j];
                bat[j]=bat[j+1];
                bat[j+1]=tbat;
            }
        }
    }
    int wkc=0;
    for (int i=0;i<5;i++){
        batlist[i]=bat[i];
        if (bat[i].wk=='Y'){
            wkc++;
        }
    }
    //Ensuring a wicket-keeper is taken into the batting line-up
    if (wkc==0){
        for (int i=0;i<n1;i++){
            if (bat[i].wk=='Y'){
                batlist[4]=bat[i];
                break;
            }
        }
    }
    Batsman tbatl;
    for (int i=0;i<6;i++){
        for (int j=0;j<5;j++){
            if (batlist[j].sr<bat[j+1].sr){
                tbatl=batlist[j];
                bat[j]=batlist[j+1];
                bat[j+1]=tbatl;
            }
        }
    }

    Bowler bowllist[4]; //The 4 bowlers in the playing 11
    Bowler tbowl;
    for (int i=0;i<n2+1;i++){
        for (int j=0;j<n2;j++){
            if (bow[j].total>bow[j+1].total){
                tbowl=bow[j];
                bow[j]=bow[j+1];
                bow[j+1]=tbowl;
            }
        }
    }
    for (int i=0;i<4;i++){
        bowllist[3-i]=bow[i];
    }
    
    Allrounder alllist[2]; //The 2 allrounders in the playing 11
    Allrounder tall;
    for (int i=0;i<n3+1;i++){
        for (int j=0;j<n3;j++){
            if (all[j].total>all[j+1].total){
                tall=all[j];
                all[j]=all[j+1];
                all[j+1]=tall;
            }
        }
    }
    alllist[0]=all[0];
    alllist[1]=all[1];
    if (all[0].battotal<all[1].battotal){
        alllist[0]=all[1];
        alllist[1]=all[0];
    }

    //Displaying the best playing 11 in batting order
    
    cout<<"The best playing 11 in batting order among the players considered is: "<<endl;
    for (int i=0;i<5;i++){
        cout<<(to_string(i+1))+". "<<batlist[i].name<<endl;
    }
    for (int i=0;i<2;i++){
        cout<<(to_string(i+6))+". "<<alllist[i].name<<endl;
    }
    for (int i=0;i<4;i++){
        cout<<(to_string(i+8))+". "<<bowllist[i].name<<endl;
    }
}