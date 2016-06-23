
#ifndef PROTO
#define PROTO

PUBLIC void	out_byte(u16 port, u8 value);
PUBLIC u8	in_byte(u16 port);
PUBLIC void	disp_str(char * info);
PUBLIC void	disp_color_str(char * info, int color);


PUBLIC void	init_prot();
PUBLIC u32	seg2phys(u16 seg);


PUBLIC void	delay(int time);

void restart();

void TestA();
void TestB();
void TestC();


PUBLIC void put_int_handle(int inter, int_handle handler);
PUBLIC void spurious_inter(int inter);


PUBLIC void clock_handler(int inter);
PUBLIC void init_clock();

PUBLIC void init_keyboard();


PUBLIC void task_tty();
PUBLIC void process_in_tty(TTY* tty, u32 key);


PUBLIC void output_char(SCREEN* scr, char ch);
PUBLIC void output_char_color(SCREEN* scr, char ch,int color);
PUBLIC void scroll(SCREEN* scr, int direction);


PUBLIC  int     printf(const char *fmt, ...);
PUBLIC  int     printinfo(const char *fmt, ...);
PUBLIC  int     printinfo_A(const char *fmt, ...);
PUBLIC  int     printinfo_B(const char *fmt, ...);
PUBLIC  int     printinfo_C(const char *fmt, ...);

PUBLIC  int     vsprintf(char *buffer, const char *fmt, va_list args);




PUBLIC  int     sys_get_ticks();
PUBLIC  int     sys_write(char* buffer, int len, PROCESS* proc);
PUBLIC  int     sys_write_info(char* buffer, int len, PROCESS* proc);
PUBLIC  int     sys_write_info_A(char* buffer, int len, PROCESS* proc);
PUBLIC  int     sys_write_info_B(char* buffer, int len, PROCESS* proc);
PUBLIC  int     sys_write_info_C(char* buffer, int len, PROCESS* proc);
PUBLIC  int     sys_write_A(char* buffer, int len, PROCESS* proc);
PUBLIC  int     sys_write_B(char* buffer, int len, PROCESS* proc);
PUBLIC  int     sys_write_C(char* buffer, int len, PROCESS* proc);

PUBLIC  void    sys_call();


PUBLIC  int     get_ticks();
PUBLIC  void    write(char* buffer, int len);
PUBLIC  void    write_info(char* buffer, int len);
PUBLIC  void    write_info_A(char* buffer, int len);
PUBLIC  void    write_info_B(char* buffer, int len);
PUBLIC  void    write_info_C(char* buffer, int len);
#endif
