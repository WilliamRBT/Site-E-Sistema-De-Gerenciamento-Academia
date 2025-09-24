import React from 'react';
import { DumbbellIcon, UsersIcon, HeartPulseIcon } from './icons';

interface FeatureCardProps {
  icon: React.ReactNode;
  title: string;
  description: string;
}

const FeatureCard: React.FC<FeatureCardProps> = ({ icon, title, description }) => {
  return (
    <div className="bg-gray-900/30 p-8 rounded-xl border border-gray-800 text-center flex flex-col items-center transform hover:-translate-y-2 transition-transform duration-300 group">
      <div className="text-orange-500 mb-5 group-hover:scale-110 transition-transform duration-300">{icon}</div>
      <h3 className="text-2xl font-bold mb-3 text-white">{title}</h3>
      <p className="text-gray-400 leading-relaxed">{description}</p>
    </div>
  );
};

const Features: React.FC = () => {
  const featuresData = [
    {
      icon: <DumbbellIcon />,
      title: 'Equipamentos Modernos',
      description: 'A melhor tecnologia para garantir seus resultados com segurança e eficiência máxima.'
    },
    {
      icon: <UsersIcon />,
      title: 'Aulas Coletivas',
      description: 'Diversas aulas para você nunca cair na rotina e treinar com amigos em um ambiente motivador.'
    },
    {
      icon: <HeartPulseIcon />,
      title: 'Nutrição Esportiva',
      description: 'Acompanhamento completo para otimizar sua dieta e acelerar seus ganhos de forma saudável.'
    }
  ];

  return (
    <section id="diferenciais" className="py-24 md:py-32 bg-[#121212]">
      <div className="container mx-auto px-6">
        <div className="text-center mb-16">
          <h2 className="text-4xl md:text-5xl font-black text-white leading-tight">Por Que a <span className="text-orange-500">GYM ELITE</span>?</h2>
          <p className="text-lg text-gray-400 mt-4 max-w-3xl mx-auto font-light">
            Oferecemos uma estrutura completa e o suporte que você precisa para alcançar seus objetivos.
          </p>
        </div>
        <div className="grid grid-cols-1 md:grid-cols-3 gap-8">
          {featuresData.map((feature, index) => (
            <FeatureCard 
              key={index}
              icon={feature.icon}
              title={feature.title}
              description={feature.description}
            />
          ))}
        </div>
      </div>
    </section>
  );
};

export default Features;