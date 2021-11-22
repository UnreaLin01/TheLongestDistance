#include<stdio.h>
#include<math.h>
#include<string.h>

void main(){
    
    int xMax = 0;
    int yMax = 0;
    scanf("%d",&xMax);
    scanf("%d",&yMax);

    static int data[7000][100] = {0};
    static char cache[100] = {0};
    
    
    for(int y = 0; y < yMax; y++){
        fflush(stdin);
        fgets(cache, (xMax + 1), stdin);
        for(int x = 0; x < xMax; x++){
            data[y][x] = (cache[x] - 48);
        }
    }
    double maxDistance = 0;
    for(int ySelect = 0; ySelect < yMax; ySelect++){
        for(int xSelect = 0; xSelect < xMax; xSelect++){
            if(data[ySelect][xSelect] == 0){
                continue;
            }
            for(int yTarget = 0; yTarget < yMax; yTarget++){
                for(int xTarget = 0; xTarget < xMax; xTarget++){
                    if(data[yTarget][xTarget] == 0){
                        continue;
                    }else if(xSelect == xTarget && ySelect == yTarget){
                        continue;
                    }
                    int ySelectCorrect = ySelect + 1;
                    int xSelectCorrect = xSelect + 1;
                    int yTargetCorrect = yTarget + 1;
                    int xTargetCorrect = xTarget + 1;
                    double distance = sqrt(pow(abs(xSelectCorrect - xTargetCorrect), 2) + pow(abs(ySelectCorrect - yTargetCorrect), 2));
                    if(distance > maxDistance){
                        maxDistance = distance;
                    }
                }
            }
        }
    }
    printf("%d",round(maxDistance));
}
