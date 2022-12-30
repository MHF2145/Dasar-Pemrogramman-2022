char teks[ukuran], fileinput[128], fileoutput[128];

    scanf("%123s", fileinput);
    strcat(fileinput, ".txt");
    
    FILE *fp = fopen(fileinput, "r");

    scanf("%123s", fileoutput);
    strcat(fileoutput, ".txt");

    FILE *fps = fopen(fileoutput, "w");