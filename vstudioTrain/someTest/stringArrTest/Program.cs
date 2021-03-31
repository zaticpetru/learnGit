using System;


namespace stringArrTest
{
    class Program
    {
        static void Main(string[] args)
        {

#if DEBUG
            Console.WriteLine("WE ARE IN DEBUG MODE");

#else
            Console.WriteLine("WE ARE NOT IN DEBUG MODE");
#endif
            Angle a = "3g 36' 53\"";
            Angle b = "4° 27' 45\"";

            Angle test;

            test = "4° 27' 45\"";


            Angle c = a + b;

            Console.WriteLine("seconds = " + c.seconds);
            Console.WriteLine(c);
            Console.WriteLine(a.ToString() + " + " + b.ToString()  + " = " + c.ToString());


            Angle d = (Angle)"-2° 20' 5\"";

            Console.WriteLine($"{b} + {d} = {b + d}");

            d = -d;
            Console.WriteLine(d);
            Console.WriteLine("{0} - {1} = {2}", b, d, (b - d));
            while (true) { }
        }

        public readonly struct Angle
        {
            public readonly int degrees;
            public readonly int minutes;
            public readonly int seconds;
            public readonly bool isNegative;

            public Angle(string angle = "0° 0' 0")
            {
                degrees = 0;
                minutes = 0;
                seconds = 0;
                isNegative = false;

                string[] items = angle.Split(" ");
                foreach(var s in items)
                {
                    switch(s[^1])
                    {
                        case 'g':
                        case '°':
                            degrees = int.Parse(s.Remove(s.Length - 1));
                            if(degrees < 0)
                            {
                                degrees = degrees * (-1);
                                isNegative = true;
                            }
                            break;
                        case '\'':
                            minutes = int.Parse(s.Remove(s.Length - 1));
                            if(minutes > 60)
                            {
                                throw new ArgumentOutOfRangeException(s, "<- bad minutes, must be < 60");
                            }
                            break;
                        case '"':
                            seconds = int.Parse(s.Remove(s.Length - 1));
                            if(seconds > 60)
                            {
                                throw new ArgumentOutOfRangeException(s, "<- bad seconds, must be < 60");
                            }
                            break;
                        default:
                            throw new ArgumentOutOfRangeException(s, "<- bad data");
                    }
                }

            }

            public Angle(int degrees = 0, int minutes = 0, int seconds = 0, bool isNegative = false)
            {
                this.degrees = degrees;
                this.minutes = minutes;
                this.seconds = seconds;
                this.isNegative = isNegative;
            }


            public static explicit operator string(Angle a)
            {
                string sign = a.isNegative ? "-" : "";
                return $"{sign}{a.degrees}° {a.minutes}' {a.seconds}\"";
            }
            public static implicit operator Angle(string str)
            {
                return new Angle(str);
            }

            public static Angle operator +(Angle a) => a;
            public static Angle operator -(Angle a) => new Angle(a.degrees, a.minutes, a.seconds, !a.isNegative);

            public static bool operator >(Angle a, Angle b)
            {
                return a.degrees > b.degrees;
            }

            public static bool operator <(Angle a, Angle b)
            {
                return a.degrees < b.degrees;
            }

            public static Angle operator +(Angle a, Angle b)
            {
                bool isNegative = false;
                int degrees = 0;
                int minutes = 0;
                int seconds = 0;
                if (a.isNegative == b.isNegative)
                {
                    seconds = a.seconds + b.seconds; // 55 + 45 + 60 + 60 = 220

                    minutes = a.minutes + b.minutes; // 10 + 7 = 17
                    minutes += seconds / 60; // 17 +=(100/60) = 1(intreg) si 40 rest
                    seconds %= 60; // seconds = seconds % 60 100/60 = rest

                    while(seconds > 60)
                    {
                        minutes++;
                        seconds = seconds - 60;
                    }

                    degrees = a.degrees + b.degrees;
                    degrees += minutes / 60;
                    minutes %= 60;

                    isNegative = a.isNegative;
                } else
                {
                    if(a > b)
                    {
                        seconds = a.seconds - b.seconds;

                        minutes = a.minutes - b.minutes;
                        while(seconds < 0)
                        {
                            seconds += 60;
                            minutes--;
                        }

                        degrees = a.degrees - b.degrees;
                        while(minutes < 0)
                        {
                            minutes += 60;
                            degrees--;
                        }

                        isNegative = a.isNegative;
                    } else
                    {
                        return b + a;
                    }

                }
                return new Angle(degrees, minutes, seconds, isNegative);
            }

            public static Angle operator -(Angle a, Angle b)
            {
                return a + new Angle(b.degrees, b.minutes, b.seconds, !b.isNegative);
            }

            public override string ToString()
            {
                string sign = isNegative ? "-" : "";
                return $"{sign}{degrees}° {minutes}' {seconds}\"";   
            }
        }
    }
}
