class FiringCircuit {
    public:
        FiringCircuit(int channel);
        bool hasFired();
        void fire();
        int getChannel();
    private:
        bool m_fired;
        int m_channel;

};