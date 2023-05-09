int remove_old_appointments(struct Appointment *queue, int current_hour) {

    

    while (queue != NULL) {

        if (queue->hour < current_hour) {

            return 1;
        }
        else {
          
            return 0;
        }
    }
}
