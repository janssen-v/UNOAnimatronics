// Blink Timing with Relay Class

class Relay
{
  public:
    Relay(int pin);
    void checkTime();
    void flipState();
  private:
    int _pin; // Pin that corresponds to relay channel
    float _push;
    float _pull;
    float _time;
};
