#ifndef SCEEN_DIRECTOR_HPP
#define SCEEN_DIRECTOR_HPP
#include "Sceen.hpp"
class SceenDirector {
	Sceen* product;
	//SceenWorker* worker;
public:
	SceenDirector() = default;
	SceenDirector(Sceen* product/*, SceenWorker* worker*/);
	void set_worker(/*SceenWorker* worker*/);
	void set_product(/*Sceen* product*/);
	void produce() {
		/*worker->make_plate(product)*/
		/*worker->make_toys(product)*/
		/*worker->checkout(product)*/
	}
	Sceen* get_produced();
	Sceen* release_product();
};
#endif