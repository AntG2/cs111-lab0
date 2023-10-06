# A Kernel Seedling
The kernel module counts the number of processes or tasks that are currently running on the system.

## Building
```shell
make
```
the make command builds the kernel module proc_count.ko from existing files.

## Running
if there is already an existing kernel module, run:
```shell
sudo rmmod proc_count.ko
```
then insert the module:
```shell
sudo insmod proc_count.ko
```
the insertion (module initialization) creates the /proc/count file
that would contain the output of the module and run the proc_count
code to count the number of current running processes.

to see results, run the command
```shell
cat /proc/count
```
to view the output of the module contained in the file

## Cleaning Up
use the command:
```shell
make clean
```
to remove the inserted module, run:
```shell
sudo rmmod proc_count.ko
```

## Testing
```python
python -m unittest
```
the command tests for 3 cases and report whether the module passes the test succesfully (indicated by .)
or fails the test (indicated by F). if a test case failed, the program reports the error causing the failure.

```shell
uname -r -s -v
```
the kernel release version tested on is Linux 5.14.8-arch1-1 #1 SMP PREEMPT SUN, 26 Sep 2021 19:36:15 +0000