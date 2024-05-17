## Hospital Appointment Scheduler

### Description
The Hospital Appointment Scheduler is a software application designed to manage appointments at a hospital or clinic. It provides functionalities for scheduling, updating, and canceling appointments for patients. Users can create new appointments, view existing appointments, modify appointment details, and remove appointments as needed.

### Objectives
- **Efficient Appointment Management**: The system aims to efficiently handle appointment scheduling, allowing users to add, update, and delete appointments seamlessly.
- **Persistent Storage**: Implement mechanisms to save appointment data to a file and load it from a file, ensuring data persistence across multiple sessions.
- **User-Friendly Interface**: The application provides a simple and intuitive command-line interface for users to interact with the system effectively.
- **Error Handling**: Gracefully handle common errors such as invalid input or attempting to modify non-existent appointments.

### Design Decisions
- **Data Storage**: Appointments are stored in a vector to facilitate dynamic resizing and efficient iteration.
- **Appointment Representation**: A struct is used to encapsulate appointment details such as patient name, appointment date, and doctor's name.
- **File I/O**: The system supports saving appointment data to a file and loading it from a file using standard file stream operations.
- **User Interface**: Interaction with the system occurs through a command-line interface, allowing users to input commands and view appointment details easily.

### Algorithms and Data Structures
- **Data Structure**: A vector is utilized to store the collection of appointments.
- **Struct Appointment**: Defines the attributes of an appointment, such as patient name, appointment date, and doctor's name.

### Screenshots
![Project Screenshot](https://github.com/yanniiie/final-proect.cpp/raw/main/photo_2024-05-17_08-48-31.jpg)


### How to Use the Software
#### Installation and Setup
1. Ensure you have a C++ compiler installed.
2. Save the provided code into a file, e.g., `hospital_appointment_scheduler.cpp`.

#### Compilation
1. Open a terminal or command prompt.
2. Navigate to the directory containing `hospital_appointment_scheduler.cpp`.
3. Compile the code using a C++ compiler, e.g., `g++ -o hospital_appointment_scheduler hospital_appointment_scheduler.cpp`.

#### Execution
1. Run the compiled program, e.g., `./hospital_appointment_scheduler`.
2. Follow the on-screen instructions to interact with the hospital appointment scheduling system.
3. Ensure that `appointment_data.txt` exists in the same directory to load the appointment data on start. The file will also be used to save the appointment data.

### Features
- **Add Appointment**: Enter the patient name, appointment date (in DD/MM/YYYY format), and doctor's name to schedule a new appointment.
- **Display Appointments**: View the list of existing appointments, including patient names, appointment dates, and doctor names.
- **Update Appointment**: Modify the details of an existing appointment by specifying its index and providing updated information.
- **Delete Appointment**: Remove an appointment from the system by specifying its index.
- **Exit**: Terminate the program and exit the application.
