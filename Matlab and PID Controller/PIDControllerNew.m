% File path to the CSV file
file_path = 'C:/Users/hp/Downloads/peakdivrms.csv';

% Set the target vibration level (setpoint)
setpoint = 0.5;

% PID constants
Kp = 0.5;
Ki = 0.1;
Kd = 0.2;

% Define variables for the PID controller
error_prior = 0;
integral = 0;

% Read RMS values from CSV file
data = csvread(file_path, 1, 0); % Skip header if exists
for i = 1:size(data, 1)
    % Extract RMS value from the first column of each row
    current_vibration = data(i, 1);

    % Calculate the error (the difference between the setpoint and current vibration)
    error = current_vibration - setpoint;

    % Calculate the integral term
    integral = integral + error;

    % Calculate the derivative term
    derivative = error - error_prior;

    % Calculate the control output
    control_output = (Kp * error + Ki * integral + Kd * derivative)/10;

    % Adjust the gearbox speed based on the control output
    adjust_gearbox_speed(control_output);

    % Update the error_prior for the next iteration
    error_prior = error;
end

function adjust_gearbox_speed(control_output)
    % Assuming this function sets the speed of the gearbox motor
    % Here, you might have code to interface with the motor controller or system

    % For illustration purposes, print the control output and simulate speed adjustment
    disp(['Control Output: ', num2str(control_output)]);

    % Simulate adjusting the gearbox speed based on the control output
    % Example: Change the speed of the gearbox motor
    % For simulation purposes, let's print a message indicating speed change
    if control_output > 0
        disp('Decrease gearbox speed.');
    elseif control_output < 0
        disp('Increasing gearbox speed.');
    else
        disp('Maintaining current gearbox speed.');
    end
end

% Example usage of the adjust_gearbox_speed function
%control_output = 0.05;  % Example control output
%adjust_gearbox_speed(control_output);  % Call the function with the control output
