#include <bits/stdc++.h>
using namespace std;

// Structure to represent an appointment
struct Appointment {
    string patientName;
    string appointmentDate; // Date format: DD/MM/YYYY
    string doctorName;
};

// Function to display all appointments
void displayAppointments(const vector<Appointment>& appointments) {
    cout << "\nAppointments:\n";
    if (appointments.empty()) {
        cout << "No appointments found.\n";
    } else {
        int index = 1;
        for (const auto& appointment : appointments) {
            cout << index << ". Patient: " << appointment.patientName
                 << ", Date: " << appointment.appointmentDate
                 << ", Doctor: " << appointment.doctorName << endl;
            index++;
        }
    }
}

// Function to add a new appointment
void addAppointment(vector<Appointment>& appointments) {
    Appointment newAppointment;
    cout << "\nEnter Patient Name: ";
    getline(cin, newAppointment.patientName);
    cout << "Enter Appointment Date (DD/MM/YYYY): ";
    getline(cin, newAppointment.appointmentDate);
    cout << "Enter Doctor's Name: ";
    getline(cin, newAppointment.doctorName);

    // Validate and add the appointment
    appointments.push_back(newAppointment);
    cout << "Appointment added successfully.\n";
}

// Function to update an existing appointment
void updateAppointment(vector<Appointment>& appointments) {
    int index;
    cout << "\nEnter the appointment index to update: ";
    cin >> index;
    cin.ignore();

    if (index > 0 && index <= appointments.size()) {
        Appointment& appointment = appointments[index - 1];
        cout << "Update Appointment Date (DD/MM/YYYY): ";
        getline(cin, appointment.appointmentDate);
        cout << "Update Doctor's Name: ";
        getline(cin, appointment.doctorName);
        cout << "Appointment updated successfully.\n";
    } else {
        cout << "Invalid appointment index.\n";
    }
}

// Function to delete an existing appointment
void deleteAppointment(vector<Appointment>& appointments) {
    int index;
    cout << "\nEnter the appointment index to delete: ";
    cin >> index;
    cin.ignore();

    if (index > 0 && index <= appointments.size()) {
        appointments.erase(appointments.begin() + index - 1);
        cout << "Appointment deleted successfully.\n";
    } else {
        cout << "Invalid appointment index.\n";
    }
}

// Function to save appointments to a file
void saveToFile(const vector<Appointment>& appointments, const string& filename) {
    ofstream FileOut(filename);
    if (FileOut.is_open()) {
        for (const auto& appointment : appointments) {
            FileOut << appointment.patientName << "," << appointment.appointmentDate << "," << appointment.doctorName << endl;
        }
        cout << "Appointments saved to file." << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
}

// Function to load appointments from a file
void loadFromFile(vector<Appointment>& appointments, const string& filename) {
    ifstream FileIn(filename);
    if (FileIn.is_open()) {
        appointments.clear(); // Clear existing appointments
        string line;
        while (getline(FileIn, line)) {
            stringstream ss(line);
            string patientName, appointmentDate, doctorName;
            getline(ss, patientName, ',');
            getline(ss, appointmentDate, ',');
            getline(ss, doctorName);
            appointments.push_back({patientName, appointmentDate, doctorName});
        }
        cout << "Appointments loaded from file." << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
}

int main() {
    vector<Appointment> appointments;
    char choice = '0';

    // Load appointments from file
    loadFromFile(appointments, "appointment_data.txt");

    while (choice != '6') {
        // Display menu
        cout << "\nHospital Appointment Scheduler\n";
        cout << "1. Display Appointments\n";
        cout << "2. Add Appointment\n";
        cout << "3. Update Appointment\n";
        cout << "4. Delete Appointment\n";
        cout << "5. Save Appointments to File\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character left in the buffer

        // Process user choice
        if (choice == '1') {
            displayAppointments(appointments);
        } else if (choice == '2') {
            addAppointment(appointments);
        } else if (choice == '3') {
            updateAppointment(appointments);
        } else if (choice == '4') {
            deleteAppointment(appointments);
        } else if (choice == '5') {
            saveToFile(appointments, "appointment_data.txt");
        } else if (choice == '6') {
            cout << "Exiting program...\n";
            // Save appointments to file before exiting
            saveToFile(appointments, "appointment_data.txt");
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

