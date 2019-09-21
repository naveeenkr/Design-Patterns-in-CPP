/*
	Author: Naveen Singh
		
	This file illustrates a basic example of strategy design pattern
  
*/

#include<iostream>

class KickBehaviour{
	public:
	virtual void kick() = 0;
};

class LightKick: public KickBehaviour{
	public:
	void kick(){
		std::cout<<"Light Kick"<<std::endl;
	}
};
class TornadoKick: public KickBehaviour{
	public:
	void kick(){
		std::cout<<"Tornado Kick"<<std::endl;
	}
};

class JumpBehaviour{
	public:
	virtual void jump() = 0;
};

class ShortJump: public JumpBehaviour{
	public:
	void jump(){
		std::cout<<"Short Jump"<<std::endl;
	}
};
class LongJump:public JumpBehaviour{
	public:
	void jump(){
		std::cout<<"Long Jump"<<std::endl;
	}
};

class Fighter{
	KickBehaviour* kick_behaviour;
	JumpBehaviour* jump_behaviour;
	public:
		Fighter(KickBehaviour* kick_b, JumpBehaviour* jump_b) : kick_behaviour(kick_b), jump_behaviour(jump_b) {};
		
		void punch(){
			std::cout<<"Punch from default fighter"<<std::endl;
		}
		void kick(){
			// encapsulates KickBehaviour Interface;
			kick_behaviour->kick();
		}
		void jump(){
			// encapsulates JumpBehaviour Interface;
			jump_behaviour->jump();
		}
		void roll(){
			std::cout<<"Roll from default fighter"<<std::endl;
		}
		virtual void display() = 0;
};

class BruceLee: public Fighter{
	public:
		BruceLee(KickBehaviour* kick_b, JumpBehaviour* jump_b) : Fighter(kick_b, jump_b) {};
		void display(){
			std::cout<<"Bruce Lee, The Great Karate fighter."<<std::endl;
		}
};

class Rambo: public Fighter{
	public:
		Rambo(KickBehaviour* kick_b, JumpBehaviour* jump_b) : Fighter(kick_b, jump_b)  {};
		void display(){
			std::cout<<"Rambo, The Great Boxer."<<std::endl;
		}
};
int main(){
	
	JumpBehaviour *short_jump = new ShortJump();
	JumpBehaviour *long_jump = new LongJump();
	KickBehaviour *tornado_kick = new TornadoKick();
	KickBehaviour *light_kick = new LightKick();
	
	
	Fighter *bruce_lee = new BruceLee(tornado_kick, long_jump);
	Fighter *rambo = new Rambo(light_kick, short_jump);
	
	bruce_lee->display();
	bruce_lee->kick();
	bruce_lee->jump();
	
	rambo->display();
	rambo->kick();
	rambo->jump();
	
	bruce_lee->punch();
	rambo->roll();
	
	return 0;
}
