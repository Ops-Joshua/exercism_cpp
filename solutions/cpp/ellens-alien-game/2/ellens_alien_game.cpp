namespace targets
{
    class Alien
    {
    private:
        int health{3};

    public:
        Alien(int x, int y)
        {
            x_coordinate = x;
            y_coordinate = y;
        }

        int get_health()
        {
            return health;
        }

        bool hit()
        {
            if (health > 0)
            {
                health -= 1;
                return true;
            }
            else
                return false;
        }

        bool is_alive()
        {
            return (0 < health);
        }

        bool teleport(int x_new, int y_new)
        {
            x_coordinate = x_new;
            y_coordinate = y_new;
            return true;
        }

        bool collision_detection( Alien the_alien)
        {
            return ((the_alien.x_coordinate == x_coordinate)
                && (the_alien.y_coordinate == y_coordinate));
        }

        int x_coordinate;
        int y_coordinate;
    };
}
