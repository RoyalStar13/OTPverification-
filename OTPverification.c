#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random OTP
int generateOTP() {
    return rand() % 10000;  // Generates a random OTP between 0000 and 9999
}

// Function to simulate sending OTP to mobile number
void sendOTP(int otp, long long mobileNumber) {
    printf("OTP sent to mobile number: %lld\n", mobileNumber);
    printf("OTP: %04d\n", otp);  // Displaying OTP for testing purposes
}

// Function to verify OTP
int verifyOTP(int generatedOTP) {
    int enteredOTP;
    printf("Enter the OTP received: ");
    scanf("%d", &enteredOTP);
    
    if (enteredOTP == generatedOTP) {
        return 1;  // OTP verified successfully
    } else {
        return 0;  // OTP verification failed
    }
}

int main() {
    long long mobileNumber;
    int otp, attempts = 3;
    
    // Seed for random number generation
    srand(time(0));

    // Get mobile number from the user
    printf("Enter your mobile number: ");
    scanf("%lld", &mobileNumber);
    
    // Generate and send OTP
    otp = generateOTP();
    sendOTP(otp, mobileNumber);
    
    // Verify OTP
    while (attempts > 0) {
        if (verifyOTP(otp)) {
            printf("OTP verified successfully!\n");
            break;
        } else {
            attempts--;
            if (attempts > 0) {
                printf("Incorrect OTP. You have %d attempt(s) left.\n", attempts);
            } else {
                printf("All attempts exhausted. OTP verification failed.\n");
            }
        }
    }
    
    return 0;
}
