#ifndef TV_H_
#define TV_H_
class Tv{
    private:
        int state;  //开还是关
        int volume;
        int maxchannel;
        int channel;    //频道
        int mode;   //有线还是电缆
        int input;  //TV or DVD
    public:
      friend class Remote;
      enum{Off, On};
      enum{MinVal, MaxVal = 20};
      enum{Antenna, Cable};
      enum{TV, DVD};

      Tv(int s = Off, int mc = 125) 
      : state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV){}
      void onoff(){
          state = (state == On) ? Off : On;
      }
      bool ison()const{
          return state == On;
      }
      bool volup();
      bool voldown();
      void chanup();
      void chandown();
      void set_mode(){
          mode = (mode == Antenna) ? Cable : Antenna;
      }
      void set_input(){
          input = (input == TV) ? DVD : TV;
      }
      void setting() const;
};

class Remote{
    private:
      int mode; //TV或DVD
    public:
      Remote(int m = Tv::TV) : mode(m){}
      void onoff(Tv &t){
          t.onoff();
      }
      bool volup(Tv &t){
          return t.volup();
      }
      bool voldown(Tv &t){
          return t.voldown();
      }
      void chanup(Tv &t){
          t.chanup();
      }
      void chandown(Tv &t){
          t.chandown();
      }
      void set_chan(Tv &t, int c){
          t.channel = c;
      }
      void set_mode(Tv &t){
          t.set_mode();
      }
      void set_input(Tv &t){
          t.set_input();
      }
};
#endif