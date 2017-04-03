// ReaperDAWHub.Playground.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../ReaperDAWHub.Controller/includes/ProjectsController.h"
#include <iostream>
#include <future>
#include "../ReaperDAWHub.Service.Client.Serialization.JSONImpl/includes/JSONSerializer.h"
#include "../ReaperDAWHub.Service.Client.RESTImpl/includes/RESTClient.h"

template<typename R>
bool isReady(std::future<R> const& f)
{
	return f.wait_for(std::chrono::seconds(-1)) == std::future_status::ready;
}

int main()
{


    return 0;
}

