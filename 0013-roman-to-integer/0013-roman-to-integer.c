int romanToInt(char * s){
    int i,su=0;
    for(i=0;i<strlen(s);i++)
    {   if(s[i]==73)
        {
            if(s[i+1]==86)
            {su+=4;
             i+=1;
            }
            else if(s[i+1]==88)
            {su+=9;
             i+=1;
            }
            else
            {su+=1;
            }
        }
        else if(s[i]==88)
        {
            if(s[i+1]==76)
            {su+=40;
             i+=1;
            }
            else if(s[i+1]==67)
            {su+=90;
             i+=1;
            }
            else
            {su+=10;
            }
        }
        else if(s[i]==67)
        {
            if(s[i+1]==68)
            {su+=400;
             i+=1;
            }
            else if(s[i+1]==77)
            {su+=900;
             i+=1;
            }
            else
            {su+=100;
            }
        }
        else if(s[i]==86)
        {   su+=5;
        } 
        else if(s[i]==76)
        {   su+=50;
        } 
        else if(s[i]==68)
        {   su+=500;
        } 
        else if(s[i]==77)
        {   su+=1000;
        }     
       
    }
    return su;
}