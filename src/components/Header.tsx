import React, { useState, useEffect } from 'react';
import { Link } from 'react-router-dom'; // Importar Link

const Header: React.FC = () => {
  const [isScrolled, setIsScrolled] = useState(false);

  useEffect(() => {
    const handleScroll = () => {
      setIsScrolled(window.scrollY > 10);
    };
    window.addEventListener('scroll', handleScroll);
    return () => window.removeEventListener('scroll', handleScroll);
  }, []);

  const navLinks = [
    { name: 'Início', href: '/' },
    { name: 'Sobre', href: '/#diferenciais' }, // Anchor link for home page section
    { name: 'Planos', href: '/#planos' },     // Anchor link for home page section
    { name: 'Contato', href: '/contato' },    // Route to ContactPage
  ];

  return (
    <header className={`fixed top-0 left-0 right-0 z-50 transition-all duration-300 ${isScrolled ? 'bg-black/50 shadow-lg backdrop-blur-md border-b border-gray-800' : 'bg-transparent'}`}>
      <div className="container mx-auto px-6 py-4 flex justify-between items-center">
        <Link to="/" className="text-2xl font-bold tracking-wider text-white">
          GYM <span className="text-orange-500">ELITE</span>
        </Link>
        <nav className="hidden md:flex space-x-8">
          {navLinks.map((link) => (
            <Link
              key={link.name}
              to={link.href}
              className="text-gray-300 hover:text-orange-500 transition-colors duration-300 font-medium text-sm tracking-wide uppercase"
            >
              {link.name}
            </Link>
          ))}
        </nav>
        {/* Mobile menu button can be added here */}
      </div>
    </header>
  );
};

export default Header;