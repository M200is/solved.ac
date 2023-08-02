    if(*p='+') {
                    if(!check_min) {
                        result+=num;
                    }
                    else {
                        result-=num;
                    }
                }
                else {
                    result-=num;
                    check_min = true;
                }
                check_num = false;