#include <stdio.h>
#include <string.h>
#define bool int
#define true 1
#define false 0
#define None '$'
int main(int argc,char *argv[]){

        //Multi-dimensional array for a 2-dimensional plane
        char map[100][100];
        //Although its intuitive that the 20 would be x and the 100 y in this case 
        //its actually backwards and the 20 is y and the 100 is x
        //this is because of the way that I implement the nested for loops later.
        
        memset(map, None, sizeof(map));
        map[2][2] ='P';
        
        //Player starting location
        //Its arbitrary where you start but I didn't want the player 
        //right next to a wall because it may add confusion

        bool proceed = true;
        bool argsCheck = false;

        int argsRunIndex = 1;


        char directions[4][10]  = {"North", "East", "South", "West"};
        int directionX[4]     = {      0,     -1,       0,      1};
        int directionY[4]     = {      1,      0,      -1,      0};
        //These arrays above are more or less behavioral storage
        //You can traverse the arrays to find what direction would 
        //represent what movement on the plane.

        int currentDirection = 0;
        //As a result of saving those values above you can save direction
        //as just an index inside of all three of those arrays.
        //You could technically instead save all three of those arrays
        //in one 2 dimensional array but that would potentially require parsing
        //later on.

        int currentPosition[2] = {2,2};


        //To see if its necessary to run any starter inputs
        if(argc-1 > 0){
            argsCheck = true;
        }
        //An example command line args input string that spells cs
        // d w w w w w w w w w w d d w w w w w w w w w w w a w w w w w w w a w w w w w w w w w w d w a w w w w w w w w a w d w w w w w w w w w w w a w w w w d a a w w w w w w w w w w w d w w w d w w w w w w w w w w w 
        // printf("argc: %d ___ %s\n",argc,argv[1]);
        //The main loop that runs until you quit
		while(proceed){

            //Nested for loops to display the map
            for(int i=0; i<20; i++){
                for(int j=0; j<100; j++){
                    if(map[i][j] == None)
                        printf("*");
                        //If there's no data leave it with this unexplored placeholder
                    else
                        printf("%c",map[i][j]); 
                        //If there is data display that data
                }
                printf("\n");
                //Will new line after each row of the plane
            }


            printf("Please traverse the world and explore using these commands: \n  W - Walk Forward\n  A - Turn Left\n  D - Turn Right\n  E - Check Direction\n  Q - Quit the Game\n");
            //Shows the user the interface each time the loop executes. 
            //Could be moved out of the main loop if you think the 
            //user can remember.

            char input = ' ';
            

            //Check and implementation of command line args input,
            //if there are no args it goes back to standard implementation
            if(!argsCheck){
                scanf(" %c", &input);
            }else{
                if(argsRunIndex == argc){
                    argsCheck=false;
                    input = 'e';
                }else{
                    input = argv[argsRunIndex][0];
                    argsRunIndex++;
                }
            }
            


            
            switch(input){
                case 'w':
                    map[currentPosition[1]][currentPosition[0]] ='#';
                    //saves the trail of where you have been
                    if(!((currentPosition[0] - directionX[currentDirection] < 0) || (currentPosition[0] - directionX[currentDirection] > 100)||(currentPosition[1] - directionY[currentDirection] < 0) || (currentPosition[1] - directionY[currentDirection] > 20))){
                        //checks if you're bumping into the edge
                        currentPosition[0] = currentPosition[0] - directionX[currentDirection];
                        currentPosition[1] = currentPosition[1] - directionY[currentDirection];
                       
                    }
                    map[currentPosition[1]][currentPosition[0]] = 'P';
                    //puts your player icon down
                    break;
                case 'a':
                    currentDirection--;
                    //moves your index up or down the 3 arrays listed above
                    if(currentDirection < 0){
                        currentDirection = 3;
                    }
                    break;
                case 'd':
                    currentDirection++;
                    //moves your index up or down the 3 arrays listed above

                    if(currentDirection > 3){
                        currentDirection = 0;
                    }
                    break;
                case 'e':
                    printf("You are facing in the %s ward direction!\n",directions[currentDirection]);
                    break;
                case 'q':

                    proceed = false;
                    break;
                
                default:
                    printf("You must enter one of the commands!\n");

            }


        }

        return 0;
}