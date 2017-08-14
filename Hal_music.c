#include "Hal_music.h" 
#include "Hal_deep.h" 
#include "Hal_delay.h" 

const tNote MyScore[ ] = 
{ 
	{L3, T/4}, 
	{L5, T/8+T/16}, 
	{L6, T/16}, 
	{M1, T/8+T/16}, 
	{M2, T/16}, 
	{L6, T/16}, 
	{M1, T/16}, 
	{L5, T/8}, 
	{M5, T/8+T/16}, 
	{H1, T/16}, 
	{M6, T/16}, 
	{M5, T/16}, 
	{M3, T/16}, 
	{M5, T/16}, 
	{M2, T/2}, 
	{ 0, 0}
}; 

//ÑÝ×àÀÖÇú
void musicPlay(void) 
{ 
	unsigned int i=0;
	while(1)
	{
		if(MyScore[i].mTime==0)break;
		beepSound(MyScore[i].mName);
		DelayMs(MyScore[i].mTime);
		i++;
		beepQuiet();
		DelayMs(10);
	}
}
  
