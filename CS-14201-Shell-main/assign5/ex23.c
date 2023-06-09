#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
Struct country
{
Char name[30];
Char capital_city [30];
Char currency[30];
Int population;
};
Int main(int argc,char*argv[])
{
Int shm_id;
Char*shm_addr;
Int*countries_num;
Struct country*countries;
Struct shmid_ds shm_desc;
Shm_id=shmget(100,2048,IPC_CREAT|IPC_EXCL\0600);
If(shm_id==-1){
Perror(“main:shmget:”);
Exit(1);
}
Shm_addr=shmat(shm_id,NULL,0);
If(!shm_addr){
Perror(“main:shmat:”);
Exit(1);
}
Countries_num=(int*)shm_addr;
*countries_num=0;
Countries=(struct country*)((void*)shm_addr sizeof(int));
Strcpy(countries[0],name,”U.S.A”);
Strcpy(countries[0],capital_city,”WASHINGTON”);
Strcpy(countries[0],currency,”U.S.DOLLAR”);
Countries[0].population=250000000;
( countries_num)  ;
Strcpy(countries[1].name,”israel”);
Strcpy(countries[1].capital_city,”jerushalem”);
Strcpy(countries[1].currency,”NEW ISRAEL SHEKED”);
Countries[1].population=6000000;
(*countries_num)  ;
Strcpy(countries[2].name,”France”);
Strcpy(countries[2].capital_city,”paris”);
Strcpy(countries[2].currency,”Frank”);
Countries[2].population=60000000;
(*countries_num)  ;
For(i=0;i<(*countries_num);i  )
{
Printf(“country%d:\n”,i 1);
Printf(“name:%d:\n”,i 1);
Printf(“currency:%s:\n”,countries[i].currency);
Printf(“population:%d:\n”,countries[i].population);
}
If(shmdt(shm_addr)==-1){
Perror(“main:shmdt:”);
}
If(shmctl(shm_id,IPC_RMID,&SHM_DESC)==-1)
{
Perror(“main:shmctl:”);
}
return 0;
}