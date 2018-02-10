/*
 * Auto Adventure
 * v01
 * Jeramy Dichiera
 *
 */

//https://gist.github.com/mariobadr/673bbd5545242fcf9482
//http://www.koonsolo.com/news/dewitters-gameloop/


#include <sys/time.h>
#include <cstdint>
#include <iostream>
#include <chrono>
#include <thread>
//mach_absolute_time
#include <mach/mach_time.h>



using namespace std;

uint64_t GetTickCount(){
	//Returns the current number of milliseconds Mac version
	//Get timebase info???
	mach_timebase_info_data_t info;
	mach_timebase_info(&info);

	uint64_t time = mach_absolute_time();

	time *= info.numer;
	time /= info.denom;

	return time / 1000000;

}

void update_game(){

	//cout << "| --update game-- |" << endl;
}

void display_game(){
	//cout << "| **display game** |" << endl;
}


int main(){
	const int TICKS_PER_SECOND = 50;
	const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
	const int MAX_FRAMESKIP = 10;

	double next_game_tick = GetTickCount();

	int loops;
	int count = 0;
	int frames = 0;
	long totalTime = 0;

	bool game_running = true;

	while(game_running){
		loops = 0;
		while(GetTickCount() > next_game_tick && loops < MAX_FRAMESKIP){
			update_game();

			next_game_tick += SKIP_TICKS;

			loops++;
		}
		frames++;
		double framecount  = frames / (GetTickCount() - next_game_tick);
		cout << framecount << endl;
		//std::chrono::seconds duration(1);

		//uint64_t start = GetTickCount();
		//std::this_thread::sleep_for(duration);
		//uint64_t end = GetTickCount();
		//double fps = 1000.0 / GetTickCount();
		//cout << fps;







//		update_game();
//		display_game();
//
//		next_game_tick += SKIP_TICKS;
//		sleep_time = next_game_tick - GetTickCount();
//
//		if(sleep_time >= 0){
//			//Pause for X sec
//			std::chrono::seconds duration(sleep_time);
//			std::this_thread::sleep_for(duration);
//		}

	}












	//cout <<  end - start ;
}


