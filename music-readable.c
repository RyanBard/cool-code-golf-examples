# include <stdio.h>

char* notes1 = "BY}6YB6%";
char* notes2 = "Qj}6jQ6%";

int getNote(int volume, int mask, int noteIndex, int octave){
    int   selection = 3 & volume >> 16;
    char* selected  = selection ? notes1 : notes2;
    int   baseNote  = selected[noteIndex % 8] + 51;
    int   note      = (baseNote * volume) >> octave;
    int   result    = 3 & mask & note;
    return result << 4;
}

int main(){
    for(int i=0;;i++){
        int n    = i >> 14;
        int s    = i >> 17;
        int ins1 = getNote(i, 1,     n,                      12);
        int ins2 = getNote(i, s,     n^i>>13,                10);
        int ins3 = getNote(i, s / 3, n + ((i >> 11) % 3),    10);
        int ins4 = getNote(i, s / 5, 8 + n -((i >> 10) % 3), 9);
        int combined = ins1 + ins2 + ins3 + ins4;
        putchar(combined);
    }
}
