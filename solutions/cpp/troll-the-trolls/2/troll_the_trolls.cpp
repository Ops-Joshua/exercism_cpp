namespace hellmath
{

    // Task 1 - Define an `AccountStatus` enumeration to represent the four
    // account types: `troll`, `guest`, `user`, and `mod`.
    enum class AccountStatus
    {
        mod,
        user,
        guest,
        troll
    };

    // Task 1 - Define an `Action` enumeration to represent the three
    // permission types: `read`, `write`, and `remove`.
    enum class Action
    {
        read,
        write,
        remove
    };

    // Task 2 - Implement the `display_post` function, that gets two arguments
    // of `AccountStatus` and returns a `bool`. The first argument is the status of
    // the poster, the second one is the status of the viewer.
    bool display_post(AccountStatus poster, AccountStatus viewer)
    {
        bool allow = false;
        switch (viewer)
        {
        case AccountStatus::mod:
        case AccountStatus::user:
        case AccountStatus::guest:
            if (poster < AccountStatus::troll)
                allow = true;
            break;
        case AccountStatus::troll:
            allow = true;
            break;
        default:
            allow = false;
        }

        return allow;
    }

    // Task 3 - Implement the `permission_check` function, that takes an
    // `Action` as a first argument and an `AccountStatus` to check against. It
    // should return a `bool`.
    bool permission_check(Action action, AccountStatus account)
    {
        bool allow = false;
        switch (action) {
        case Action::read:
            //if (AccountStatus::troll >= account)
                allow = true;
            break;
        case Action::write:
            if (AccountStatus::guest != account)
                allow = true;
            break;
        case Action::remove:
            if (AccountStatus::mod == account)
                allow = true;
            break;
        }

        return allow;
    }

    // Task 4 - Implement the `valid_player_combination` function that
    // checks if two players can join the same game. The function has two parameters
    // of type `AccountStatus` and returns a `bool`.
    // the poster, the second one is the status of the viewer.
    bool valid_player_combination(AccountStatus playerA, AccountStatus playerB)
    {
        bool allow = false;
        switch (playerA)
        {
        case AccountStatus::mod:
        case AccountStatus::user:
            if (AccountStatus::guest > playerB)
                allow = true;
            break;
        case AccountStatus::guest:
            //allow = false;
            break;
        case AccountStatus::troll:
            if (AccountStatus::troll == playerB)
                allow = true;
            break;
        default:
            allow = false;
        }

        return allow;
    }


    // Task 5 - Implement the `has_priority` function that takes two
    // `AccountStatus` arguments and returns `true`, if and only if the first
    // account has a strictly higher priority than the second.
    bool has_priority(AccountStatus first, AccountStatus second)
    {
       return (first < second);
    }
} // namespace hellmath
