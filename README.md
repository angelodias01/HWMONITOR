# HWMonitor Project

## Overview

**HWMonitor** is a Python-based hardware monitoring tool designed to track and log critical system parameters in real-time. It is ideal for system administrators, developers, and hardware enthusiasts who need to monitor system performance, diagnose issues, or analyze hardware behavior over time.

The tool collects data such as CPU temperature, usage, clock speed, GPU performance, RAM usage, and external temperature readings from a serial device (e.g., an Arduino-based sensor). The collected data is stored in a CSV file for later analysis and can also be transmitted via a serial port for real-time monitoring.

---

## Key Features

- **CPU Monitoring**:
  - Logs CPU package temperature.
  - Tracks CPU usage (percentage).
  - Monitors CPU clock speed (MHz).

- **GPU Monitoring**:
  - Supports multiple NVIDIA GPUs.
  - Captures GPU temperature, utilization (%), and memory usage (MB).

- **RAM Monitoring**:
  - Tracks RAM usage (percentage).
  - Logs total available memory (MB).

- **External Sensors**:
  - Reads external temperature sensors connected via a serial port (e.g., Arduino).
  - Supports custom sensor configurations.

- **Data Logging**:
  - Saves all collected data in a CSV file for easy analysis.
  - Real-time data is printed to the console.

- **Serial Communication**:
  - Sends monitoring data via serial communication to external devices (optional).

---

## Use Cases

- **System Performance Monitoring**:
  - Track CPU, GPU, and RAM usage to identify bottlenecks or performance issues.

- **Hardware Diagnostics**:
  - Monitor temperatures and usage to detect overheating or hardware failures.

- **Environmental Monitoring**:
  - Use external sensors to monitor air intake and exhaust temperatures in server rooms or other environments.

- **Data Analysis**:
  - Analyze logged data over time to identify trends or optimize system performance.

---

## Requirements

- **Python Libraries**:
  - `psutil`, `wmi`, `pyserial`, and `pynvml` must be installed.

- **Open Hardware Monitor**:
  - Required for CPU temperature readings. Must be running in the background.

- **NVIDIA GPU**:
  - Required for GPU monitoring using the `pynvml` library.

- **External Temperature Sensor (Optional)**:
  - Connect an Arduino or similar device with a temperature sensor to a serial port.

---

## Output

- **CSV File**:
  - All collected data is saved in a CSV file (`hardware_log.csv` by default) for easy analysis.

- **Real-Time Console Output**:
  - Real-time monitoring data is printed to the console for immediate feedback.

- **Serial Communication (Optional)**:
  - Monitoring data can be sent to external devices via serial communication.

---

## Example Use Case

Imagine you are managing a server room and want to ensure that your systems are running within safe temperature ranges. HWMonitor can log CPU and GPU temperatures, RAM usage, and external air temperatures. If temperatures exceed safe thresholds, you can take corrective action before hardware damage occurs.

---

## License

This project is open-source and available under the **MIT License**. Feel free to modify, distribute, and use it for personal or commercial purposes.

---

## Get Started

To get started with HWMonitor, clone or download the project, install the required dependencies, and run the script. For detailed setup and usage instructions, refer to the full documentation.
