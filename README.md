HWMonitor

Overview

HWMonitor is a Python-based hardware monitoring tool that records and logs system parameters such as CPU temperature, usage, clock speed, GPU performance, RAM usage, and external temperature readings from a serial device (e.g., an Arduino-based sensor). The collected data is stored in a CSV file for later analysis and can also be transmitted via a serial port.

Features

Logs CPU temperature, usage, and clock speed

Monitors multiple GPUs, capturing temperature, utilization, and memory usage

Tracks RAM usage and total available memory

Reads external temperature sensors connected via a serial port (e.g., Arduino)

Saves all collected data in a CSV file

Prerequisites

Before running HWMonitor, ensure that the following dependencies are installed:

pip install psutil wmi pyserial pynvml

Additionally, you must have:

Open Hardware Monitor installed and running (needed for CPU temperature readings)

An NVIDIA GPU (for GPU monitoring via pynvml)

An external temperature sensor connected via a serial port (optional)

Setup

Clone or download the HWMonitor project to your local machine.

Ensure Open Hardware Monitor is running in the background.

If using an external temperature sensor, connect it to the appropriate serial port.

Modify log_file in the script to specify the desired CSV output location.

Update the serial port (COM5 by default) if necessary.

Usage

Run the script using:

python hwmonitor.py

Press Ctrl + C to stop monitoring.

Output

The script prints real-time monitoring data to the console.

Data is saved in a CSV file (hardware_log.csv) for analysis.

If a serial device is connected, the script sends monitoring data via serial communication.

Example Log Entry

Timestamp, CPU Package Temp (°C), CPU Usage (%), CPU Clock Speed (MHz), GPU Name, GPU Temp (°C), GPU Usage (%), GPU Memory Usage (MB), RAM Usage (%), Total RAM (MB), TempAirIn (°C), TempAirOut (°C)
2025-02-08 12:00:00, 65, 30, 3200, GPU 0 (RTX 3080), 70, 40, 5000, 45, 16384, 25, 30

Troubleshooting

Error opening serial port: Ensure the correct port is set (COM5 by default) and that no other applications are using it.

No CPU temperature data: Verify that Open Hardware Monitor is running and properly configured.

No GPU data: Ensure an NVIDIA GPU is installed and that the pynvml library is functioning correctly.

License

This project is open-source and available under the MIT License.
