class Igraph
{
    private:
    public:
        Igraph() = default;
        Igraph(int x, int y, std::string name);
        virtual ~Igraph() = default;

        virtual void initWindow() = 0;
        virtual void setSprite(std::string id, std::string t_path, int x, int y, int inx, int iny) = 0;

        virtual void draw(std::string id) = 0;
        virtual void display() = 0;
        virtual bool isOpen() = 0;
        virtual void clear() = 0;
};