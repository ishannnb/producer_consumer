# Consumer_producer

A Producer-Consumer program involves coordinating processes where one process (the producer) generates items and places them in a shared memory area, while another process (the consumer) retrieves and uses those items from the same memory space. This program operates concurrently, meaning the producer and consumer can work simultaneously.

Note: C++ compiler is inbuilt in the Linux

If you want to run this program on a Windows system, you'll need to have a C++ compiler installed. Additionally, you'll have to add the compiler's path to the system environment variables for it to be recognized.

```bash
Importing the file locally
```

## Clone the Repository

```console 
foo@bar % git clone https://github.com/ishannnb/producer_consumer.git

```
# Executing the Program 

``` console 
foo@bar % g++ producer.cpp -pthread -o producer
foo@bar % g++ consumer.cpp -pthread -o consumer
foo@bar % ./producer & ./consumer &

```
# Output 
``` console 
[1] 1505
[2] 1506
foo@bar %

Produced (item 0 )
Produced (item 1 )
Consumed (item 0 )
Produced (item 2 )
Consumed (item 1 )
Consumed (item 2 )
Produced (item 3 )
Consumed (item 3 )
Produced (item 4 )
Produced (item 5 )
Consumed (item 4 )
Consumed (item 5 )
Produced (item 6 )
Consumed (item 6 )
Produced (item 7 )
Produced (item 8 )
Consumed (item 7 )
Produced (item 9 )
Consumed (item 8 )

[1]  - done       ./producer
foobar %  Consumed (item 9 )

[2]  + done       ./consumer
 





