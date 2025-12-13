# Philosophers
A project about resurrecting threads to eat spaghetti with 'borrowed' forks

## How to run
run `make` to compile the paired version into `./philo` and semaphore version into `./semaphore_philo`

## Paired Philo
run ./philo with the following ARGS
- number of philosophers: The number of philosophers and also the number of forks.
- time to die (in milliseconds): If a philosopher has not started eating within time to die milliseconds since the start of their last meal or the start of the simulation, they die.
- time to eat (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
- time to sleep (in milliseconds): The time a philosopher will spend sleeping.
- number of times each philosopher must eat (optional argument): If all philosophers have eaten at least number of times each philosopher must eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.

#### Example
./philo 4 100 40 20 5

### Implementation Details

#### Parsing
The numbers are parsed into positive decimals and put into the t_data struct. In case of an invalid input, instructions are printed. A global mutex for state printing is also created.

#### Initialization
Based on the data, philo structs are initialized into a linked list, each with unique id, and a fork mutex wrapper struct. The list is a circular list, The id(1) is considered as head;

#### Start
A start time is set as the last_eaten time. The philosophers are resurected by creating a new thread, each with a 1ms delay to ensure they don't steal each other's forks. They immediatly try to take their own fork, and the fork of their right collegue. If the forks are not available they wait.

#### Monitoring
The parent thread parses the list looking for the end conditions. If any of the philosophers has 'expired' if so, it sets the end flag. It prevents future printing, and tells the living philosophers to die.
It also monitors if if all philosophers have eaten total_eat_count times, if so it stops monitoring.

#### End
The program waits, using the pthread_join, for all philosopher threads to end. Then it destroys the mutex'es and the philosopher structs.

## Semaphore Philo
Work in progress
