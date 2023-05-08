int get_current_hour() {
    time_t now = time(NULL);
    struct tm *local_time = localtime(&now);
    int hour = local_time->tm_hour;
    return hour;
}