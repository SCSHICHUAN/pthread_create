//
//  main.c
//  C线程的创建
//
//  Created by SHICHUAN on 2017/5/24.
//  Copyright © 2017年 SHICHUAN. All rights reserved.
//

/*
 pthread_create函数
 原型：int  pthread_create（（pthread_t  *thread,  pthread_attr_t  *attr,  void  *（*start_routine）（void  *）,  void  *arg）
 用法：#include  <pthread.h>
 功能：创建线程（实际上就是确定调用该线程函数的入口点），在线程创建以后，就开始运行相关的线程函数。
 说明：thread：线程标识符；
 attr：线程属性设置；
 start_routine：线程函数的起始地址；
 arg：传递给start_routine的参数；
 返回值：成功，返回0；出错，返回-1。
 */


#include <unistd.h> //sleep();
#include <stdio.h>
#include <pthread.h>

void thread_1()
{
    int i = 0;
    while (1) {
        i+=1;
        sleep(1);
        printf("2B我是线程一 %d次\n",i);
    }
}

void thread_2()
{
    int i = 0;
    while (1) {
        i+=1;
        sleep(2);
        printf("2B我是线程二 %d次\n",i);
    }
}


void thread_3()
{
    int i = 0;
    while (3) {
        i+=1;
        sleep(3);
        printf("2B我是线程三 %d次\n",i);
    }
}

int main(int argc, const char * argv[]) {
   
    //线程开始的地址
    pthread_t star_location_1,star_location_2,star_location_3;
    int ret;
    //创建线程
    ret = pthread_create(&star_location_1, NULL,(void *)thread_1, NULL);
    if (ret == !0) {
        printf("creat_error_1");
    }
    
    ret = pthread_create(&star_location_2, NULL,(void *)thread_2, NULL);
    if (ret == !0) {
        printf("creat_error_2");
    }
    
    ret = pthread_create(&star_location_3, NULL,(void *)thread_3, NULL);
    if (ret == !0) {
        printf("creat_error_2");
    }

    
    /*等待线程结束*/
    pthread_join(star_location_1, NULL);
    pthread_join(star_location_2, NULL);
    pthread_join(star_location_3, NULL);
    
    
    
    return 0;
}













