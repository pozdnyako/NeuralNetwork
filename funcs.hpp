/*
FUNC( name, num,
     {code} val -> activated_val,
     {code} val, activated_val -> derived_val
     )
*/

FUNC( TANH, 1,
    {
        activated_val = tanh(val);
    },
    {
        derived_val = (1.0 - activated_val * activated_val);
    })
FUNC( RELU, 2,
    {
        if(val > 0)
            activated_val = val;
        else
            activated_val = 0.01 * val;
    },
    {
        if(val > 0)
            derived_val = 1;
        else
            derived_val = 0.01;
    })
FUNC( SIGM, 3,
    {
        activated_val = 1 / (1 + exp(-val));
    },
    {
        derived_val = activated_val * (1 - activated_val);
    }) // alpha = 0.5
