#include <kipr/botball.h>

void distance_sensor();
void lower_arm();
int main()
{

    //in start box, move forward until get to PVC pipe
    distance_sensor();

    //pause wheels
    motor(0,0);
    motor(1,0);
    msleep(100);

    //lower arm to grab PVC pipe
    lower_arm();

    //move backwards to drop bridge
    motor(0,-80);
    motor(1,-80);
    msleep(1800);

    //turn left toward line
    motor(0, 0);
    motor(1, -50);
    msleep(1500);

    motor(0,0);
    motor(1,0);
    msleep(100);

motor(0,80);
    motor(1,80);
    msleep(2100);

    motor(0,0);
    motor(1,0);
    msleep(100);

    motor(1,0);
    motor(0,80);
    msleep(800);

        int counter = 0;
    while(counter < 2000) {
       if (analog(5) < 300 ) //this means it's white, so turn right toward line
       {
        motor(1,80);
            motor(0,20);
        }
        else if(analog(4)<300)
        {
            motor(1,20);
            motor(0,80);
        }

        msleep(100);
        counter = counter + 100;
    }

    motor(0,0); //stop
    motor(1,0);
    msleep(100);

    motor(1,0); //turn left to move cupper in position
    motor(0,100);
    msleep(1117);

    motor(0,0); //stop
    motor(1,0);
    msleep(100);

    motor(1,80);
    motor(0,80);
    msleep(400);

    motor(0,0); //stop
    motor(1,0);
    msleep(100);

    motor(2,-80); //raise arm out of cup
    msleep(300);

    motor(0,0); //stop
    motor(1,0);
    msleep(100);

    motor(1,-80); //back up
    motor(0,-80);
    msleep(700);

    motor(0,0); //stop
    motor(1,0);
    msleep(100);

    motor(1,0); //turn around
    motor(0,80);
    msleep(2500);

    distance_sensor();

    motor(0,0); //stop
    motor(1,0);
    msleep(100);

    motor(0,80); //turn to pvc
    motor(1,0);
    msleep(1800);

    motor(0,0); //stop
    motor(1,0);
    msleep(100);

      while(analog(0)<2900){
       if(digital(0)==0){
           motor(0,30);
           motor(1,50);
       }
       else {
           motor(0,50);
           motor(1,10);

       }
   }

    motor(0,0); //stop
    motor(1,0);
    msleep(100);

    motor(1,0);
    motor(0,80);
    msleep(1800);

    motor(1,80);
    motor(0,80);
    msleep(800);


    int counter2 = 0;
    while(counter2<10000){
        if(digital(0)==0){
            motor(0,20);
            motor(1,50);
            msleep(70);
        }
        else {
            motor(0,50);
            motor(1,20);
            msleep(70);
        }

        msleep(5);
        counter2 = counter2+100;


    }


    return 0;
}

//functions

void distance_sensor()
{
    while (analog(0) < 2900)
    {
    //move forward
    motor(0,80);
        motor(1,80);
    }
}

void lower_arm()
{
    int counter = 0;
    int stop_position = 1300;
    while(counter < stop_position)
    {
        counter += 50;
        motor(2,25);
        msleep(50);
        motor(2,0);
        msleep(25);
    }
}
