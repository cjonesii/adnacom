// function pointers as used in observer pattern

#include <stdio.h>

#define OBS_SZ 10

typedef void (*observer)(float temperature);
observer observers[OBS_SZ] = {NULL};
static float temperature = 0.0f;

void display_temperature(float t)
{
	printf("Display Temperature: %.2f degC\n", t);
}

void send_temperature(float t)
{
	printf("Send Temperature: %.2f degC\n", t);
}

// execute the registered functions in the observer function pointer array
void notify_observers()
{
	for (int i = 0; i < OBS_SZ; i++) {
		if ((*observers[i]) != NULL)
			(*observers[i])(temperature);
	}
}

void update_temperature(float t)
{
	temperature = t;
	notify_observers();
}

int main(int argc, char *argv[])
{
	// register observers
	observers[0] = display_temperature; // note that there is no addressof in front of function name
	observers[1] = send_temperature;

	// emulating a function that captures the changes in the variable to be observed
	update_temperature(24.5f);
	update_temperature(-10.0f);

	return 0;
}