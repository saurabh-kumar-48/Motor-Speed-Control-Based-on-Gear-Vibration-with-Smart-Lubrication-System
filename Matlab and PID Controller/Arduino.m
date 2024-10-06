% Connect to Arduino
port = "COM3";
baudrate = 9600;
arduino = serialport(port, baudrate);
configureTerminator(arduino, "LF");

% Control loop
fprintf("Arduino connected. Type '1' to turn motor ON, '0' to turn it OFF.\n");
while true
    % Read user input
    userInput = input("Enter command (1=motor ON, 0=motor OFF, q=quit): ", 's');
    
    % Exit loop if user types 'q'
    if userInput == "q"
        break;
    end
    
    % Send command to Arduino
    writeline(arduino, userInput);
    
    % Read and display response from Arduino
    response = readline(arduino);
    disp("Arduino response: " + response);
end

% Close serial port
fclose(arduino);
delete(arduino);
clear arduino;
disp("Serial port closed.");


% Connect to Arduino
port = "COM3"; 
baudrate = 9600;
arduino = serialport(port, baudrate);
configureTerminator(arduino, "LF");

% Control loop
fprintf("Arduino connected.\n");
while true
    % Prompt user for motor control command
    userInput = input("Enter motor command (F=Forward, B=Backward, S=Stop, q=quit): ", 's');
    
    % Exit loop if user types 'q'
    if userInput == "q"
        break;
    end
    
    % Send command to Arduino
    writeline(arduino, userInput);
    
    % Wait for Arduino response (optional)
    pause(0.1);
end

% Close serial port
fclose(arduino);
delete(arduino);
clear arduino;
disp("Serial port closed.");
